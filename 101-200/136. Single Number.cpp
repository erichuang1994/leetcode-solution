#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (auto i : nums) {
      ans = ans ^ i;
    }
    return ans;
  }
};
int main() {
  Solution a;
  int v[] = {1};
  vector<int> c(v, v + 1);
  cout << a.singleNumber(c);
  return 0;
}
