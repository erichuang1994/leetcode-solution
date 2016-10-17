class Solution {
public:
  int climbStairs(int n) {
    int f1 = 1, f2 = 2;
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    int tmp;
    for (int i = 3; i <= n; ++i) {
      tmp = f1 + f2;
      f1 = f2;
      f2 = tmp;
    }
    return f2;
  }
};
