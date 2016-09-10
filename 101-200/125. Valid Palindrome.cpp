class Solution {
public:
  bool isPalindrome(string s) {
    if (s.length() == 0) {
      return true;
    }
    int end = s.length() - 1;
    int begin = 0;
    int len = s.length();
    while (begin < len) {
      while (begin < len && !(isalpha(s[begin]) || isdigit(s[begin]))) {
        begin++;
      }
      while (end >= 0 && !(isalpha(s[end]) || isdigit(s[end]))) {
        end--;
      }
      if (begin >= len) {
        return true;
      }
      if (tolower(s[begin++]) != tolower(s[end--])) {
        return false;
      }
    }
    return true;
  }
};
