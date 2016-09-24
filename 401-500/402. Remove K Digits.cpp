#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl
class Solution {
public:
  string removeKdigits(string num, int k) {
    if (k == 0)
      return num;
    int len = num.size();
    int size = k;
    string ret;
    ret.push_back(num[0]);
    for (int i = 1; i < len; i++) {
      while (ret.size() != 0 && ret.back() > num[i] && k-- > 0) {
        ret.pop_back();
      }
      if (ret.size() != 0 || num[i] != '0') {
        ret.push_back(num[i]);
      }
    }
    ret = ret.substr(0, len - size);
    if (ret.size() == 0) {
      return "0";
    }
    return ret;
  }
};
int main() {
  Solution a;
  cout << a.removeKdigits("9", 1);
}
