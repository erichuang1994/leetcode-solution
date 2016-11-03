// 维护元素可以向右扩展的最大长度,注意进栈的时候要考虑可以向左扩展的最大长度
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<pair<int, int>> s;
    int ret = 0;
    s.emplace(0, -1);
    for (int i = 0; i < heights.size(); ++i) {
      int last = -1;
      while (!s.empty() && s.top().first > heights[i]) {
        auto tmp = s.top();
        last = tmp.second;
        s.pop();
        ret = max(ret, (i - tmp.second) * tmp.first);
      }
      if (s.top().first < heights[i])
        if (last != -1)
          s.emplace(heights[i], last);
        else
          s.emplace(heights[i], i);
    }
    while (!s.empty()) {
      auto tmp = s.top();
      s.pop();
      ret = max(ret, ((int)heights.size() - tmp.second) * tmp.first);
    }
    return ret;
  }
};
