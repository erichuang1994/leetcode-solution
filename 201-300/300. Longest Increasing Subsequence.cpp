class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> ret;
    for (int i = 0; i < nums.size(); ++i) {
      auto k = lower_bound(ret.begin(), ret.end(), nums[i]);
      if (k == ret.end()) {
        ret.push_back(nums[i]);
      } else {
        *k = nums[i];
      }
    }
    return ret.size();
  }
};
