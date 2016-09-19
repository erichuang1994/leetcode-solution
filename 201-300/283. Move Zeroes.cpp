class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int i, j;
    int len = nums.size();
    for (i = 0; i < len; i++) {
      if (nums[i] == 0) {
        break;
      }
    }
    if (i == len)
      return;
    for (j = i + 1; j < len; j++) {
      if (nums[j] != 0) {
        nums[i++] = nums[j];
        nums[j] = 0;
      }
    }
  }
};
