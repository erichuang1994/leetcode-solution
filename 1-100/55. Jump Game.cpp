class Solution {
public:
  bool canJump(vector<int> &nums) {
    int right = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i <= right) {
        right = max(right, i + nums[i]);
      } else {
        return false;
      }
      if (right >= nums.size() - 1)
        return true;
    }
    return false;
  }
};
