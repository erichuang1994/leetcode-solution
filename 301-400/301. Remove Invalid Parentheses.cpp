class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    int lp = 0, rp = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
      if (*it == '(')
        ++lp;
      else if (*it == ')') {
        if (lp > 0)
          --lp;
        else
          ++rp;
      }
    }
    set<string> ret;
    string cur = "";
    dfs(s, 0, lp, rp, 0, cur, ret);
    return vector<string>(ret.begin(), ret.end());
  }
  void dfs(string &s, int cur, int lp, int rp, int pair, string &curstr,
           set<string> &ret) {
    if (cur == s.size() && lp == 0 && rp == 0 && pair == 0) {
      ret.insert(curstr);
      return;
    }
    if (cur == s.size() || pair < 0) {
      return;
    }
    if (s[cur] == '(') {
      if (lp > 0) {
        dfs(s, cur + 1, lp - 1, rp, pair, curstr, ret);
      }
      curstr.push_back(s[cur]);
      dfs(s, cur + 1, lp, rp, pair + 1, curstr, ret);
      curstr.pop_back();
    } else if (s[cur] == ')') {
      if (rp > 0) {
        dfs(s, cur + 1, lp, rp - 1, pair, curstr, ret);
      }
      curstr.push_back(s[cur]);
      dfs(s, cur + 1, lp, rp, pair - 1, curstr, ret);
      curstr.pop_back();
    } else {
      curstr.push_back(s[cur]);
      dfs(s, cur + 1, lp, rp, pair, curstr, ret);
      curstr.pop_back();
    }
  }
};
