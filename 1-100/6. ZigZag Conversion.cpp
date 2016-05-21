#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    string ret(s);
    int cur = 0;
    int lenStr = s.length();
    int cycle = numRows * 2 - 1;
    for (int i = 0; i < numRows; i++) {
      if (i == 0 || i == numRows - 1) {
        for (int j = i; j < lenStr; j += (cycle - 1)) {
          ret[cur++] = s[j];
        }
      } else {
        for (int j = i; j < lenStr; j += (cycle - 1)) {
          ret[cur++] = s[j];
          if (j + cycle - 1 - 2 * i < lenStr) {
            ret[cur++] = s[j + cycle - 1 - 2 * i];
          }
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution a;
  string s = "PAYPALISHIRING";
  string v = "ABC";
  string c = "ABCD";
  cout << a.convert(s, 3) << endl;
  cout << a.convert(v, 2) << endl;
  cout << a.convert(c, 3) << endl;
  return 0;
}
