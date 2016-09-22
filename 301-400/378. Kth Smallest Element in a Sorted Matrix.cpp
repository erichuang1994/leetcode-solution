class Solution {
  struct node {
    int val, idx;
    node(int val, int idx) {
      this->val = val;
      this->idx = idx;
    }
    bool operator<(const node &b) const { return val > b.val; }
  };

public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int len = matrix.size();
    int idxy[len];
    priority_queue<node> q;
    for (int i = 0; i < len; i++) {
      idxy[i] = 0;
      q.emplace(matrix[i][0], i);
    }
    int ret;
    // node *tmp;
    while (k-- > 0) {
      auto tmp = q.top();
      ret = tmp.val;
      q.pop();
      if (idxy[tmp.idx] + 1 < len) {
        idxy[tmp.idx]++;
        q.emplace(matrix[tmp.idx][idxy[tmp.idx]], tmp.idx);
      }
    }
    return ret;
  }
};
