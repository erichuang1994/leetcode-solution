class NumArray {
  vector<int> f;

public:
  NumArray(vector<int> &nums) {
    int v = 0;
    for (auto num : nums) {
      v += num;
      f.push_back(v);
    }
  }

  int sumRange(int i, int j) { return f[j] - (i > 0 ? f[i - 1] : 0); }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
