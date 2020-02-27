class Solution {
public:
  double myPow(double x, int n) {
    if (!n) {
      return 1;
    } else if (n == 1) {
      return x;
    } else if (n == -1) {
      return 1 / x;
    }

    
    double a = myPow(x, n / 2);
    double b = (n > 0) ? x : 1 / x;

    if (n % 2 == 0) { 
      return a * a;
    } else { 
      return a * a * b;
    }
  }
};
