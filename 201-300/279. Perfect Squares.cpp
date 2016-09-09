class Solution {
public:
  int numSquares(int n) {
    vector<int> res(n + 1, 0);
    int tmp;
    for (int i = 1; i <= n; i++) {
      if (pow(int(pow(i, 0.5)), 2) == i) {
        res[i] = 1;
        continue;
      }
      tmp = -1;
      for (int j = 1; j * j <= i; j++) {
        tmp = tmp == -1 ? res[i - j * j] + 1 : min(tmp, res[i - j * j] + 1);
      }
      res[i] = tmp;
    }
    return res[n];
  }
};
