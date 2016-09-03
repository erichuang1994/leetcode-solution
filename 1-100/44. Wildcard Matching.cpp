class Solution {
public:
  bool isMatch(string s, string p) {
    int lens = s.length();
    int lenp = p.length();
    if (p.empty() && !s.empty()) {
      return false;
    }
    if (s.empty()) {
      for (int i = 0; i < lenp; i++) {
        if (p[i] != '*') {
          return false;
        }
      }
      return true;
    }
    // dp[0] for empty
    int dp[lens + 1];
    if (p[0] == '*') {
      fill_n(dp, lens + 1, 1);
    } else if (p[0] == '?') {
      fill_n(dp, lens + 1, 0);
      dp[1] = 1;
    } else {
      fill_n(dp, lens + 1, 0);
      dp[1] = p[0] == s[0] ? 1 : 0;
    }
    for (int i = 1; i < lenp; i++) {
      if (p[i] == '*') {
        bool flag = dp[0];
        for (int j = 0; j <= lens; j++) {
          flag = flag | dp[j];
          dp[j] = flag;
        }
      } else if (p[i] == '?') {
        for (int j = lens; j > 0; j--) {
          dp[j] = dp[j - 1] == 1 ? 1 : 0;
        }
        dp[0] = 0;
      } else {
        for (int j = lens; j > 0; j--) {
          dp[j] = dp[j - 1] == 1 && p[i] == s[j - 1] ? 1 : 0;
        }
        dp[0] = 0;
      }
    }
    return dp[lens];
  }
};
