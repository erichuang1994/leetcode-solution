class Solution {
public:
  string longestPalindrome(string s) {
    auto len = 2 * s.length() - 1;
    int l[len];
    for (int i = 0; i < len; i++)
      l[i] = 1;
    for (int x = 1; x < len - 1;) {
      int y;
      for (y = l[x] + 1; x - y + 1 >= 0 && x + y - 1 < len; y++) {
        if ((x - y + 1) % 2 == 1) {
          continue;
        } else {
          if (s[(x - y + 1) / 2] != s[(x + y - 1) / 2]) {
            break;
          }
        }
      }
      y--;
      l[x] = max(1, (x + y - 1) % 2 == 1 ? y - 1 : y);
      if (l[x] == 1) {
        x++;
        continue;
      }
      for (int y = 1; y < l[x]; y++) {
        l[x + y] = min(l[x] - y, l[x - y]);
        if (l[x + y] + x + y - 1 == x + l[x] - 1) {
          x = x + y;
          break;
        }
      }
    }
    int c = 0, tmp;
    for (int i = 0; i < len; i++) {
      c = l[i] > l[c] ? i : c;
    }
    return s.substr(c / 2 - l[c] / 2 + (c % 2), l[c]);
  }
};
