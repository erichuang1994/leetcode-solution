class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length())
      return false;
    if (s1.length() == 0) {
      if (s2 == s3) {
        return true;
      } else {
        return false;
      }
    }
    if (s2.length() == 0) {
      if (s1 == s3) {
        return true;
      } else {
        return false;
      }
    }
    int len_s1 = s1.length();
    int len_s2 = s2.length();
    int len_s3 = s3.length();
    bool f[s1.length() + 1][s2.length() + 1];
    for (int i = 0; i < len_s1 + 1; i++) {
      for (int j = 0; j < len_s2 + 1; j++) {
        f[i][j] = false;
      }
    }
    queue<pair<int, int>> curr;
    queue<pair<int, int>> next;
    curr.push(make_pair(0, 0));
    f[0][0] = true;
    for (int m = 0; m < s3.length(); m++) {
      int n = curr.size();
      if (n == 0) {
        return false;
      }
      while (n--) {
        auto t = curr.front();
        curr.pop();
        if (t.first < len_s1 && s1[t.first] == s3[m] &&
            f[t.first + 1][t.second] != true) {
          curr.push(make_pair(t.first + 1, t.second));
          f[t.first + 1][t.second] = true;
        }
        if (t.second < len_s2 && s2[t.second] == s3[m] &&
            f[t.first][t.second + 1] != true) {
          curr.push(make_pair(t.first, t.second + 1));
          f[t.first][t.second + 1] = true;
        }
      }
    }
    if (curr.empty()) {
      return false;
    } else {
      return true;
    }
  }
};
