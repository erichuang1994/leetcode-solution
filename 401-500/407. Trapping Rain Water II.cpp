#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    if (heightMap.size() == 0) {
      return 0;
    }
    int dire[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    vector<vector<int>> H(heightMap);
    vector<vector<int>> W(heightMap);
    int R, C;
    int h_max = 0;
    R = heightMap.size();
    C = heightMap[0].size();
    for (int x = 0; x < R; x++) {
      for (int y = 0; y < C; y++) {
        h_max = max(H[x][y], h_max);
      }
    }
    for (int x = 0; x < R; x++) {
      for (int y = 0; y < C; y++) {
        if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
          W[x][y] = H[x][y];
        } else {
          h_max = max(H[x][y], h_max);
          W[x][y] = h_max;
        }
      }
    }
    bool over = false;
    while (!over) {
      over = true;
      for (int x = 1; x < R - 1; x++) {
        for (int y = 1; y < C - 1; y++) {
          int tmp = 999999999;
          for (int k = 0; k < 4; k++) {
            tmp = min(tmp, W[x + dire[k][0]][y + dire[k][1]]);
          }
          if (tmp < W[x][y] && H[x][y] < W[x][y]) {
            over = false;
            W[x][y] = max(tmp, H[x][y]);
          }
        }
      }
    }
    int ret = 0;
    for (int x = 1; x < R - 1; x++) {
      for (int y = 1; y < C - 1; y++) {
        ret += W[x][y] - H[x][y];
      }
    }
    return ret;
  }
};
int main() {
  Solution a;
  vector<vector<int>> vec(
      {{1, 3, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 3}, {3, 3, 3, 2, 3, 1}});
  cout << a.trapRainWater(vec);
}
