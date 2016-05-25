#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int numTrees(int n) {
    if (n == 0)
      return 0;
    int dp[n][n];
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }
    for (int step = 1; step < n; step++) {
      for (int i = 0; i < n - step; i++) {
        dp[i][i + step] = 0;
        // 处理没有左子树的情况
        dp[i][i + step] += dp[i + 1][i + step];
        // 处理没有右子树的情况
        dp[i][i + step] += dp[i][i + step - 1];
        for (int root = i + 1; root < i + step; root++) {
          dp[i][i + step] += dp[i][root - 1] * dp[root + 1][i + step];
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main() {
  Solution a;
  cout << a.numTrees(3) << endl;
  return 0;
}
