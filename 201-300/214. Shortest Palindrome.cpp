class Solution {
public:
  bool check(string &s, int a, int b) {
    if (a % 2 == 0 && b % 2 == 0) {
      return true;
    }
    if (a % 2 == 1 && b % 2 == 1) {
      return s[a / 2] == s[b / 2];
    }
    return false;
  }
  string shortestPalindrome(string s) {
    if (s == "") {
      return s;
    }
    int p[2 * s.size() + 1];
    int center, right;
    int bound = 2 * s.size() + 1;
    p[0] = 0;
    p[1] = 1;
    center = 1;
    right = 2;
    int left, tmpright, count;
    for (int i = 2; i < bound; i++) {
      if (p[2 * center - i] + i >= right) {
        left = 2 * i - right;
        tmpright = right;
        count = 0;
        while (1) {
          left--;
          tmpright++;
          if (left >= 0 && tmpright < bound && check(s, left, tmpright))
            count++;
          else
            break;
        }
        p[i] = tmpright - i - 1;
        center = i;
        right = tmpright - 1;
      } else {
        p[i] = p[2 * center - i];
      }
    }
    for (int i = 2 * s.size(); i >= 0; i--) {
      if (p[i] == i) {
        string ret = s.substr(i);
        reverse(ret.begin(), ret.end());
        return ret + s;
      }
    }
    return s;
  }
};
