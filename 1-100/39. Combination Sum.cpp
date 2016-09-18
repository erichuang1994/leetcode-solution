#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {

public:
  void dfs(vector<vector<int>> &ret, vector<int> &combin, int target, int pos,
           vector<int> &nums) {
    if (target == nums[pos]) {
      combin.push_back(nums[pos]);
      ret.push_back(combin);
      combin.pop_back();
      return;
    }
    if (pos < nums.size() && nums[pos] < target) {
      combin.push_back(nums[pos]);
      dfs(ret, combin, target - nums[pos], pos, nums);
      combin.pop_back();
      dfs(ret, combin, target, pos + 1, nums);
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ret;
    if (candidates.size() == 0)
      return ret;
    vector<int> combin;
    this->dfs(ret, combin, target, 0, candidates);
    return ret;
  }
};
int main() {
  Solution a;
  vector<int> input = {2, 3, 6, 7};
  // cout << "here" << endl;
  cout << a.combinationSum(input, 7).size() << endl;
}
