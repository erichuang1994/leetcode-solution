class Solution {
public:
  void solver(vector<int> &nums, int &ret, const int &k) {
    // pruning before binary search
    int cur = 0;
    int best = INT_MIN;
    for (auto &num : nums) {
      cur = max(cur + num, num);
      best = max(best, cur);
    }
    if (best <= k) {
      ret = max(ret, best);
      return;
    }
    set<int> s;
    s.insert(0);
    cur = 0;
    for (auto &num : nums) {
      cur += num;
      auto it = s.lower_bound(cur - k);
      if (it != s.end())
        ret = max(ret, cur - *it);
      s.insert(cur);
    }
  }
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    vector<vector<int>> &mat = matrix;
    int ret = -1e9;
    for (size_t i = 0; i < mat[0].size(); ++i) {
      vector<int> nums(mat.size(), 0);
      for (size_t j = i; j < mat[0].size(); ++j) {
        for (int x = 0; x < mat.size(); ++x)
          nums[x] += mat[x][j];
        solver(nums, ret, k);
        if (ret == k)
          return k;
      }
    }
    return ret;
  }
};
