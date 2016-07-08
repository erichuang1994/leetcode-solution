#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  void reverseWords(string &s) {
    string ret(s);
    int len = s.length();
    int last = 0;
    int status = 0; // status = 0 上一个是' ' status = 1上一个不是' '
    int i_ret = len - 1;
    for (int i = 0; i < len; i++) {
      if (s[i] == ' ' && status == 1) {
        if (i_ret != len - 1) {
          ret[i_ret--] = ' ';
        }
        for (int j = i - 1; j >= last; j--) {
          ret[i_ret--] = s[j];
        }
        last = i + 1;
        status = 0;
      } else if (s[i] == ' ' && status == 0) {
        last = i + 1;
      } else {
        status = 1;
      }
    }
    if (status == 1) {
      if (i_ret != len - 1) {
        ret[i_ret--] = ' ';
      }
      for (int j = len - 1; j >= last; j--) {

        ret[i_ret--] = s[j];
      }
    }
    if (len == 0) {
      return;
    }
    s = ret.substr(i_ret + 1);
  }
};
