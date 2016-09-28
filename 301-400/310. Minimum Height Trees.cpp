class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
    vector<int> degree(n, 0);
    vector<vector<int>> p(n);
    if (n == 1 || n == 2) {
      vector<int> ret;
      for (int i = 0; i < n; i++)
        ret.push_back(i);
      return ret;
    }
    for (auto &edge : edges) {
      degree[edge.first]++;
      degree[edge.second]++;
      p[edge.first].push_back(edge.second);
      p[edge.second].push_back(edge.first);
    }
    int idx = 0;
    stack<int> leaves[2];
    int num = 0;
    for (int i = 0; i < n; i++) {
      if (degree[i] == 1) {
        leaves[idx].push(i);
      }
    }
    while (!leaves[idx].empty()) {
      while (!leaves[idx].empty()) {
        auto tmp = leaves[idx].top();
        leaves[idx].pop();
        num++;
        for (auto &n : p[tmp]) {
          degree[n]--;
          if (degree[n] == 1) {
            leaves[(idx + 1) % 2].push(n);
          }
        }
      }
      if (num == n - 1 || num == n - 2) {
        break;
      }
      idx = (idx + 1) % 2;
    }
    vector<int> ret;
    idx = (idx + 1) % 2;
    while (!leaves[idx].empty()) {
      ret.push_back(leaves[idx].top());
      leaves[idx].pop();
    }
    return ret;
  }
};
