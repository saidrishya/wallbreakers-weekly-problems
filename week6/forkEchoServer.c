#include <stdio.h>
#include <stdlib.h> // for exit
#include <sys/socket.h> // for socket
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

#define TRUE 1
#define IOBUF_LEN 1024

void sigchld_handler(int s) {
  while(waitpid(-1, NULL, WNOHANG) > 0);
}

int write_data(int socket, char *buf, int count) {
  int nwritten, total = 0;
  while (total < count) {
    nwritten = write(socket, buf, count - total);
    if (nwritten == 0) return total;
    if (nwritten == -1) return -1;
    total += nwritten;
    buf += nwritten;
  }
  return total;
}

void print_buf(char* buf, int n) {
  while (n > 0) {
    char c = *buf;
    fprintf(stderr, "%c(%d)", c, c);
    buf++;
    n--;
  }
}

int main(void) {
  // create a TCP Stream socket
  int s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) return -1;
  
  // set socket option: reuseaddr
  int on = 1;
  if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
    return -1;
  }
  
  // create an address and bind the socket to it
  struct sockaddr_in sa;
  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_port = htons(1986);
  sa.sin_addr.s_addr = htonl(INADDR_ANY);
  char *bind_address = "127.0.0.1";
  if (inet_aton(bind_address, &sa.sin_addr) == 0) {
    printf("invalid bind address\n");
    close(s);
    return -1;
  }
  
  // bind socket to sa
  if (bind(s, (struct sockaddr*)&sa, sizeof(sa)) == -1) {
    printf("can't bind on this address.\n");
    close(s);
    return -1;
  }
  
  // ok, socket has been created and binded to an address, now listen on this socket now...
  if (listen(s, 511) == -1) { // this magic 511 backlog value is fron nginx
    printf("error! listen: %s\n", strerror(errno));
    close(s);
    return -1;
  }
  
  // register signal handler
  struct sigaction sig_a;
  sig_a.sa_handler = sigchld_handler; // reap all dead processes
  sigemptyset(&sig_a.sa_mask);
  sig_a.sa_flags = SA_RESTART;
  if (sigaction(SIGCHLD, &sig_a, NULL) == -1) {
    printf("register signal handler failed.\n");
    return -1;
  }
  
  // all right, now we listen for new connections on this socket and handle them in a infinite loop
  struct sockaddr_in peer_addr;
  socklen_t addr_len = sizeof(peer_addr);
  while(TRUE) {
    int new_socket = accept(s, (struct sockaddr*)&peer_addr, &addr_len);
    if (new_socket == -1) {
      perror("can't accept connection on socket");
      exit(-1);
    }
    pid_t pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(0);
    }
    
    if (pid == 0) {
      // in child process
      close(s);
      char buf[IOBUF_LEN];
      while (TRUE) {
        int nread = read(new_socket, buf, IOBUF_LEN);
        if (nread == -1) {
          fprintf(stderr, "error reading from client: %s\n", strerror(errno));
          exit(-1);
        } else if (nread == 0) {
          fprintf(stderr, "client closed connection!\n");
          close(new_socket);
          exit(0);
        } else if (nread > 0) {
          print_buf(buf, nread);
          write_data(new_socket, buf, nread);
        }
      }
    } else if (pid > 0) {
      // in parent process
      close(new_socket);
    }
  }
  
  return 0;
}forkEcho
