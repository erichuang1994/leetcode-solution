// Version 1
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    if (n == 0)
      return vector<vector<int>>();
    vector<vector<int>> ret(n, vector<int>(n, -1));
    int num = 1;
    int dire[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = 0, y = 0;
    int idx = 0;
    while (1) {
      ret[x][y] = num;
      if (num == n * n)
        return ret;
      ++num;
      int nx = x + dire[idx][0];
      int ny = y + dire[idx][1];
      if (0 <= nx && nx < n && 0 <= ny && ny < n && ret[nx][ny] == -1) {
        x = nx;
        y = ny;
      } else {
        idx = (idx + 1) % 4;
        x = x + dire[idx][0];
        y = y + dire[idx][1];
      }
    }
    return ret;
  }
};
// Version 2
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    if (n == 0)
      return vector<vector<int>>();
    vector<vector<int>> ret(n, vector<int>(n, 0));
    int num = 1;
    int dire[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = 0, y = 0;
    for (int k = n; k > 0; k -= 2) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < k - 1; ++j) {
          ret[x][y] = num;
          if (num == n * n)
            return ret;
          ++num;
          x += dire[i][0];
          y += dire[i][1];
        }
      }
      x++;
      y++;
    }
    ret[--x][--y] = num;
    return ret;
  }
};
