class Solution {
public:
  bool isHappy(int n) {
    set<int> s;
    while (n != 1) {
      int tmp = 0;
      long long base = 1;
      if (s.find(n) != s.end()) {
        return false;
      }
      s.insert(n);
      while (base <= n) {
        int digit = (n / base) % 10;
        tmp += digit * digit;
        base *= 10;
      }
      n = tmp;
    }
    return true;
  }
};
