class Solution {
public:
  void sortColors(vector<int> &nums) {
    int zero_end, two_begin;
    zero_end = 0;
    two_begin = nums.size() - 1;
    int temp;
    int i = 0;
    while (i <= two_begin) {
      // cout << nums[i] << endl;
      if (nums[i] == 0) {
        temp = nums[zero_end];
        nums[zero_end++] = 0;
        nums[i] = temp;
        i++;
      } else if (nums[i] == 2) {
        temp = nums[two_begin];
        nums[two_begin--] = 2;
        nums[i] = temp;
      } else if (nums[i] == 1) {
        i++;
      }
    }
  }
};
