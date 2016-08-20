class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<pair<int, int>> pii;
    for (int i = 0; i < nums.size(); ++i) {
      pii.push_back(make_pair(nums[i], i));
    }
    sort(pii.begin(), pii.end());
    vector<int> res;
    for (int head = 0, tail = pii.size() - 1; head < tail; ++head) {
      while (pii[head].first + pii[tail].first > target)
        --tail;
      if (pii[head].first + pii[tail].first == target) {
        res.push_back(min(pii[head].second, pii[tail].second));
        res.push_back(max(pii[head].second, pii[tail].second));
        break;
      }
    }
    return res;
  }
};
