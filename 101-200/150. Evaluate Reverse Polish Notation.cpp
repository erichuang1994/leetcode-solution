#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    vector<int> nums;
    int ans = 0;
    for (auto i : tokens) {
      // cout << i << endl;
      if (i == "+") {
        int b = nums.back();
        nums.pop_back();
        int a = nums.back();
        nums.pop_back();
        nums.push_back(a + b);

      } else if (i == "-") {
        int b = nums.back();
        nums.pop_back();
        int a = nums.back();
        nums.pop_back();
        // printf("%d %d", b, a);
        nums.push_back(a - b);

      } else if (i == "*") {
        int b = nums.back();
        nums.pop_back();
        int a = nums.back();
        nums.pop_back();
        nums.push_back(a * b);

      } else if (i == "/") {
        int b = nums.back();
        nums.pop_back();
        int a = nums.back();
        nums.pop_back();
        nums.push_back(a / b);
      } else {

        nums.push_back(atoi(i.c_str()));
      }
    }
    return nums.back();
  }
};

int main() {
  Solution a;
  vector<string> str;
  str.push_back("4");
  str.push_back("13");
  str.push_back("5");
  str.push_back("/");
  str.push_back("+");
  cout << a.evalRPN(str) << endl;
}
