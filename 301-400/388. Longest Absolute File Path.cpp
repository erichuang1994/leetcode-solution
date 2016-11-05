class Solution {
public:
  int lengthLongestPath(string input) {
    stack<int> s;
    int len = 0;
    int ret = 0;
    int tmpdepth;
    for (auto i = 0; i < input.size();) {
      tmpdepth = 0;
      for (; i < input.size() && input[i] == '\t'; ++i, ++tmpdepth)
        ;
      while (!s.empty() && s.size() > tmpdepth) {
        len -= s.top();
        s.pop();
      }
      bool flag = false;
      int savei = i;
      for (; i < input.size() && input[i] != '\n'; ++i) {
        if (input[i] == '.')
          flag = true;
      }
      len += i - savei;
      if (flag)
        ret = max(ret, len + tmpdepth);
      s.push(i - savei);
      i++;
    }
    return ret;
  }
};
