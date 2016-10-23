class Solution {
public:
  string toHex(int num) {
    string base = "0123456789abcdef";
    unsigned n = (unsigned)num;
    string ret;
    if (num == 0) {
      return "0";
    }
    while (n > 0) {
      ret.push_back(base[n % 16]);
      n >>= 4;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
