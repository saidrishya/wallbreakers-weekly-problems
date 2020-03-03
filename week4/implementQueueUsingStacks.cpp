class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    int front;
    MyQueue() {
        front=0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty()) front=x;
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s1.empty()){
            int l = s1.top();
             s1.pop();
            s2.push(l);           
        }
        
        int ret = s2.top();
        s2.pop();
        
        if(!s2.empty()) front = s2.top();
        while(!s2.empty()){
            int l = s2.top();
            s2.pop();
            s1.push(l);
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
