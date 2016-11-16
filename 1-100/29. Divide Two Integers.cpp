class Solution {
  typedef long long ll;

public:
  int divide(int dividend, int divisor) {
    ll a = dividend;
    ll b = divisor;
    int sign;
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
      sign = -1;
    } else {
      sign = 1;
    }
    a = abs(a);
    b = abs(b);
    ll ret = 0;
    for (int i = 0; i <= 32; ++i) {
      if ((b << i) > a) {
        for (int j = i; j >= 0; --j) {
          if ((b << j) <= a) {
            ret += (1L << j);
            a -= (b << j);
          }
        }
        ret *= sign;
        if (ret < INT_MIN || ret > INT_MAX)
          return INT_MAX;
        else
          return ret;
      }
    }
    return -1;
  }
};
