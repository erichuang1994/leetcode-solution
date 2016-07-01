class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int count = 0;
    int num = nums[0] - 1;
    for (auto i : nums) {
      if (num != i && count == 0) {
        num = i;
      } else if (num == i) {
        count++;
      } else {
        count--;
      }
    }
    return num;
  }
};
