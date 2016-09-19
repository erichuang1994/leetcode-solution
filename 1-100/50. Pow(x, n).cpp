class Solution {
public:
  double myPow(double x, int n) {
    long long nums = n;
    if (nums < 0) {
      x = (double)1.0 / x;
      nums = -nums;
    }
    double ret = 1;
    while (nums > 0) {
      if (nums & 1) {
        ret *= x;
      }
      x *= x;
      nums >>= 1;
    }
    return ret;
  }
};
