class Solution {
  vector<int> nums1, nums2;
  struct Node {
    int sum;
    int x, y, idx, idy;
    Node(int x, int y, int idx, int idy) {
      this->x = x;
      this->y = y;
      this->idx = idx;
      this->idy = idy;
      this->sum = x + y;
    }
    bool operator<(const Node &b) const { return sum > b.sum; }
  };

public:
  vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                        int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    vector<pair<int, int>> ret;
    priority_queue<Node> q;
    if (nums1.size() == 0 || nums2.size() == 0) {
      return ret;
    }
    int i = 0, j = 0;
    q.push(Node(nums1[0], nums2[0], 0, 0));
    while (k-- > 0 && q.size()) {
      auto tmp = q.top();
      q.pop();
      ret.emplace_back(tmp.x, tmp.y);
      if (tmp.idx + 1 < len1) {
        q.push(Node(nums1[tmp.idx + 1], nums2[tmp.idy], tmp.idx + 1, tmp.idy));
      }
      if (tmp.idx == 0 && tmp.idy + 1 < len2) {
        q.push(Node(nums1[tmp.idx], nums2[tmp.idy + 1], tmp.idx, tmp.idy + 1));
      }
    }
    return ret;
  }
};
