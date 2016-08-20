class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    if (n == 0 || k == 0)
      return res;
    vector<int> tmp;
    dfs(n, k, res, tmp);
    return res;
  }
  void dfs(int n, int k, vector<vector<int>> &res, vector<int> &tmp) {
    if (k == 0) {
      res.push_back(vector<int>(tmp));
      return;
    }
    for (int j = n; j - k >= 0; j--) {
      tmp.push_back(j);
      dfs(j - 1, k - 1, res, tmp);
      tmp.pop_back();
    }
    return;
  }
};
