class Solution {
public:
  int missingNumber(vector<int> &nums) {
    long long sum = 0;
    int maximum = INT_MIN;
    for (auto &num : nums) {
      sum += num;
      maximum = max(maximum, num);
    }
    if (nums.size() - 1 == maximum)
      return nums.size();
    return (maximum + 1) * (maximum) / 2 - sum;
  }
};
