class Solution {
public:
  int getMoneyAmount(int n) {
    int dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; ++i) {
      for (int j = 0; j < n + 1; ++j) {
        dp[i][j] = 0;
      }
    }
    for (int step = 1; step < n; ++step) {
      for (int i = 1; i <= n - step; ++i) {
        int tmp = 1e9;
        for (int k = i; k <= i + step; ++k) {
          tmp = min(tmp, max(dp[i][k - 1], dp[k + 1][i + step]) + k);
        }
        dp[i][i + step] = tmp;
      }
    }
    return dp[1][n];
  }
};
