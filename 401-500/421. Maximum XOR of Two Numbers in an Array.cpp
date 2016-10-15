class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    int max = 0, mask = 0;
    unordered_set<int> s;
    for (int i = 31; i >= 0; --i) {
      mask = mask | (1 << i);
      s.clear();
      for (auto &num : nums) {
        s.insert(num & mask);
      }
      auto tmp = max | (1 << i);
      for (auto v : s) {
        if (s.find(v ^ tmp) != s.end()) {
          max = tmp;
          break;
        }
      }
    }
    return max;
  }
};
