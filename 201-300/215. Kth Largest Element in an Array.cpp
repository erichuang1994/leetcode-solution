class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int l = 0, r = nums.size();
    k = nums.size() - k + 1;
    int ret;
    srand(time(0));
    while (1) {
      swap(nums[l], nums[rand() % (r - l) + l]);
      int tmp = nums[l];
      int i = l + 1;
      for (int j = l + 1; j < r; ++j) {
        if (nums[j] <= tmp) {
          swap(nums[i++], nums[j]);
        }
      }
      if (i - l == k) {
        ret = tmp;
        break;
      } else if (i - l < k) {
        k -= (i - l);
        l = i;
      } else {
        l = l + 1;
        r = i;
      }
    }
    return ret;
  }
};
