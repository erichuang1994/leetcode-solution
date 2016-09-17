class Solution {
public:
  int pow_mod(int x, int y, int mod) {
    int ret = 1;
    while (y >= 1) {
      if (y & 1) {
        ret = (long long)ret * x % mod;
      }
      x = (long long)x * x % mod;
      y >>= 1;
    }
    return ret;
  }
  int superPow(int a, vector<int> &b) {
    if (b.empty()) {
      return 1;
    }
    const int mod = 1337;
    int last_bit = b.back();
    b.pop_back();
    return pow_mod(superPow(a, b), 10, 1337) * pow_mod(a, last_bit, 1337) %
           1337;
  }
};
