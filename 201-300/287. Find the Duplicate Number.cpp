class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    if (nums.size() > 0) {
      int slow = 0;
      int fast = nums[slow];
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }
      int head = 0;
      slow = nums[slow];
      while (slow != head) {
        head = nums[head];
        slow = nums[slow];
      }
      return slow;
    } else
      return -1;
  }
};
