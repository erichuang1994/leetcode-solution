// 84的变形
class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0)
      return 0;
    vector<int> f(matrix[0].size() + 1, 0);
    int ret = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j)
        f[j] = matrix[i][j] == '1' ? f[j] + 1 : 0;
      stack<int> s;
      for (int j = 0; j < f.size(); ++j) {
        while (!s.empty() && f[s.top()] >= f[j]) {
          auto tmp = s.top();
          s.pop();
          int sidx = s.empty() ? 0 : s.top() + 1;
          ret = max(ret, (j - sidx) * f[tmp]);
        }
        s.push(j);
      }
    }
    return ret;
  }
};
// 下面的代码在leetcode上比上面的代码快一点点 不知道什么原因
// class Solution {
// public:
//   int maximalRectangle(vector<vector<char>> &matrix) {
//     if (matrix.size() == 0)
//       return 0;
//     vector<int> f(matrix[0].size(), 0);
//     int ret = 0;
//     for (int i = 0; i < matrix.size(); ++i) {
//       for (int j = 0; j < matrix[0].size(); ++j)
//         f[j] = matrix[i][j] == '1' ? f[j] + 1 : 0;
//       stack<int> s;
//       for (int j = 0; j < matrix[0].size(); ++j) {
//         while (!s.empty() && f[s.top()] >= f[j]) {
//           auto tmp = s.top();
//           s.pop();
//           int sidx = s.empty() ? 0 : s.top() + 1;
//           ret = max(ret, (j - sidx) * f[tmp]);
//         }
//         s.push(j);
//       }
//       while (!s.empty()) {
//         auto tmp = s.top();
//         s.pop();
//         int sidx = s.empty() ? 0 : s.top() + 1;
//         ret = max(ret, ((int)matrix[0].size() - sidx) * f[tmp]);
//       }
//     }
//     return ret;
//   }
// };
