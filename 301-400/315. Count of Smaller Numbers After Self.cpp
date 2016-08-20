// naive tree version
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
// merge sort version
class Solution {
public:
  void mergeSort(vector<pair<int, int>> &nums, int l, int r, vector<int> &ret,
                 vector<pair<int, int>> &tmp) {
    if (l == r) {
      return;
    }
    int mid = (l + r) / 2;
    // sort
    this->mergeSort(nums, l, mid, ret, tmp);
    this->mergeSort(nums, mid + 1, r, ret, tmp);
    // merge
    int x = mid;
    int y = r;
    for (int i = r; i >= l; i--) {
      if (x == l - 1) {
        while (i >= l) {
          tmp[i--] = nums[y--];
        }
        break;
      }
      if (y == mid) {
        while (i >= l) {
          tmp[i--] = nums[x--];
        }
        break;
      }
      if (nums[x].first <= nums[y].first) {
        tmp[i] = nums[y--];
      } else {
        tmp[i] = nums[x];
        ret[nums[x--].second] += y - mid;
      }
    }
    for (int i = l; i <= r; i++) {
      nums[i] = tmp[i];
    }
  }
  vector<int> countSmaller(vector<int> &nums) {
    if (nums.empty())
      return vector<int>();
    vector<int> ret(nums.size(), 0);
    vector<pair<int, int>> tmp(nums.size(), make_pair(0, 0));
    vector<pair<int, int>> nums_index;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      nums_index.push_back(make_pair(nums[i], i));
    }
    mergeSort(nums_index, 0, nums.size() - 1, ret, tmp);
    return ret;
  }
};
