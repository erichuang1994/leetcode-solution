#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> ret;
    dfs(ret, 0, n - 1);
    return ret;
  }
  void dfs(vector<int> &ret, int cur, int n) {
    if (n == -1) {
      ret.push_back(cur);
      return;
    }
    dfs(ret, cur, n - 1);
    dfs(ret, (ret.back()) ^ (1 << n), n - 1);
  }
};
int main() {
  Solution a;
  a.grayCode(2);
  return 0;
}
