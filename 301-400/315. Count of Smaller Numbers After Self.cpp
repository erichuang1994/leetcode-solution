struct Node {
  int counts;
  bool tag;
  int addition;
  Node *left, *right;
  Node() {
    counts = 0;
    addition = 0;
    left = right = NULL;
  }
};
class IntervalTree {
public:
  int l, r;
  Node *head;
  IntervalTree(int left, int right) {
    l = left;
    r = right;
    head = new Node();
    head->counts = 0;
  };
  void update(Node *n, int left, int right) {
    if (left < right) {
      if (n->left == NULL) {
        n->left = new Node();
        n->right = new Node();
        n->left->counts = n->right->counts = n->counts;
      }
    }
    if (n->addition > 0) {
      n->counts += n->addition;
      if (left < right) {
        n->left->addition += n->addition;
        n->right->addition += n->addition;
      }
      n->addition = 0;
    }
  }
  void insert(int value) {
    Node *n = this->head;
    int left = this->l;
    int right = this->r;
    while (left != value) {
      int mid = (left + right) / 2;
      if (n->left == NULL) {
        n->left = new Node();
        n->right = new Node();
        n->left->counts = n->right->counts = n->counts;
      }
      if (mid < value) {
        left = mid + 1;
        n = n->right;
      } else {
        n->right->addition++;
        right = mid;
        n = n->left;
      }
    }
    n->addition++;
  }
  int ask(int value) {
    int target = value - 1;
    int left = this->l;
    int right = this->r;
    if (target < left)
      return 0;
    Node *n = this->head;
    while (left < target) {
      int mid = (left + right) / 2;
      update(n, left, right);
      if (target > mid) {
        left = mid + 1;
        n = n->right;
      } else {
        right = mid;
        n = n->left;
      }
    }
    update(n, left, right);
    return n->counts;
  }
};
class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    if (nums.empty()) {
      return vector<int>();
    }
    int l, r;
    l = nums[0];
    r = nums[0];
    for (auto num : nums) {
      l = min(num, l);
      r = max(num, r);
    }
    if (l < 0) {
      int len = nums.size();
      for (int i = 0; i < len; i++) {
        nums[i] += -l;
      }
      r = r - l;
      l = 0;
    }
    IntervalTree t(l, r);
    int len = nums.size();
    vector<int> res(len, 0);
    for (int i = len - 1; i >= 0; i--) {
      res[i] = t.ask(nums[i]);
      t.insert(nums[i]);
    }
    cout << endl;
    return res;
  }
};
