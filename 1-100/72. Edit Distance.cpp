#include <string>
using namespace std;
class Solution {
public:
  int minDistance(string word1, string word2) {
    word1 = " " + word1;
    word2 = " " + word2;
    int len1 = word1.length();
    int len2 = word2.length();
    int dp[len2];
    for (int j = 0; j < len2; j++) {
      dp[j] = j;
    }
    int last = 0;
    int tmp;
    for (int i = 1; i < len1; i++) {
      last = dp[0];
      dp[0] = i;
      for (int j = 1; j < len2; j++) {
        tmp = dp[j];
        dp[j] = min(
            {dp[j - 1] + 1, dp[j] + 1, last + (word1[i] == word2[j] ? 0 : 1)});
        last = tmp;
      }
    }
    return dp[len2 - 1];
  }
};
int main() {}
