class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int len = 0;
    long base = 1;
    while (base <= x) {
      len++;
      base *= 10;
    }
    long base2 = 1;
    base /= 10;
    for (int i = 0; i < len / 2; i++) {
      if ((x / base2) % 10 != (x / base) % 10)
        return false;
      base2 *= 10;
      base /= 10;
    }
    return true;
  }
};
