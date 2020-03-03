class Solution {
public:
  double myPow(double x, int n) {
      if(n==0) return 1;
      double ans=1;
      long long  temp = n;
      temp = abs(temp);
      while(temp){
          if(temp%2 == 1){
              ans*=x;
              temp-=1;
          }
          else{
              x*=x;
              temp/=2;
          }
      }
      
      return (n>0)? ans : (1/ans);
   
  }
};
