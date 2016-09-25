class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() == 0) {
      return 0;
    }
    int max = 0;
    for (auto &h : height) {
      max = std::max(h, max);
    }
    vector<int> w(height.size(), max);
    bool over = false;
    auto len = height.size();
    w[0] = height[0];
    w[len - 1] = height[len - 1];
    over = true;
    for (int i = 1; i < len - 1; i++) {
      int tmp = min(w[i - 1], w[i + 1]);
      if (w[i] != height[i] && tmp < w[i]) {
        over = false;
        w[i] = std::max(tmp, height[i]);
      }
    }
    for (int i = len - 1; i > 0; i--) {
      int tmp = min(w[i - 1], w[i + 1]);
      if (w[i] != height[i] && tmp < w[i]) {
        over = false;
        w[i] = std::max(tmp, height[i]);
      }
    }
    int ret = 0;
    for (int i = 0; i < len; i++) {
      ret += (w[i] - height[i]);
    }
    return ret;
  }
};
