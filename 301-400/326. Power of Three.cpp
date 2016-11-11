class Solution {
public:
  const int MAX3POWER = 1162261467;
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
    return MAX3POWER % n == 0;
  }
};
