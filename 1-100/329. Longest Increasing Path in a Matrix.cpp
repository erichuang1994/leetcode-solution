#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    vector<vector<int>> save(matrix.size(), vector<int>(matrix[0].size(), 0));
    dfs(save, matrix, 0, 0);
    int ret = 0;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        ret = max(ret, save[i][j]);
      }
    }
    return ret;
  }
  int dfs(vector<vector<int>> &save, vector<vector<int>> &matrix, int x,
          int y) {
    if (save[x][y] != 0) {
      return save[x][y];
    }
    int dire[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ret = 0;
    for (int i = 0; i < 4; i++) {
      int tempx = x + dire[i][0];
      int tempy = y + dire[i][1];
      if (0 <= tempx && tempx < matrix.size() && 0 <= tempy &&
          tempy < matrix[0].size()) {
        if (matrix[tempx][tempy] > matrix[x][y]) {
          ret = max(ret, dfs(save, matrix, tempx, tempy));
        }
      }
    }
    ret++;
    save[x][y] = ret;
    return ret;
  }
};

int main() { return 0; }
