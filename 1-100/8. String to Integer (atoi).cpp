class Solution {
public:
  int myAtoi(string str) {
    unsigned long ret = 0;
    const long MAX = (long)INT_MAX + 1;
    int flag = 1;
    int len = str.size();
    int pos = str.find_first_not_of(' ');
    if (len == 0) {
      return 0;
    }
    if (str[pos] == '+') {
      pos++;
    } else if (str[pos] == '-') {
      flag = -1;
      pos++;
    }
    for (; pos < len; ++pos) {
      if (isdigit(str[pos])) {
        ret = ret * 10 + (str[pos] - '0');
        if (ret > MAX)
          break;
      } else {
        break;
      }
    }
    if (flag == 1) {
      return ret > INT_MAX ? INT_MAX : ret;
    } else {
      return ret > MAX ? INT_MIN : -1 * ret;
    }
  }
};
