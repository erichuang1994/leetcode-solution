#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// dijstra+priority_queue
// class Solution {
// private:
//   struct Node {
//     int dis;
//     int x, y;
//     Node() {}
//     Node(int dis, int x, int y) {
//       this->dis = dis;
//       this->x = x;
//       this->y = y;
//     }
//     bool friend operator<(Node a, Node b) { return a.dis > b.dis; }
//   };
//   struct NodeCom {
//     bool operator()(const Node *a, const Node *b) const {
//       return a->dis > b->dis;
//     }
//   };
//
// public:
//   int minPathSum(vector<vector<int>> &grid) {
//     int Max = 99999999;
//     int m = grid.size();
//     int n = grid[0].size();
//     // cout << "m=" << m << " n=" << n << endl;
//     int dis[m][n];
//     bool flag[m * n];
//     for (int i = 0; i < m; i++) {
//       for (int j = 0; j < n; j++) {
//         dis[i][j] = Max;
//         flag[i * n + j] = false;
//       }
//     }
//     dis[0][0] = grid[0][0];
//     priority_queue<Node *, vector<Node *>, NodeCom> q;
//     q.push(new Node(grid[0][0], 0, 0));
//     while (flag[m * n - 1] == false) {
//       Node *temp;
//       while (!q.empty()) {
//         temp = q.top();
//         q.pop();
//         if (flag[(temp->x) * n + temp->y] == false) {
//           break;
//         }
//         delete temp;
//       }
//       flag[(temp->x) * n + temp->y] = true;
//       if (temp->y + 1 < n) {
//         int distemp = dis[temp->x][temp->y] + grid[temp->x][temp->y + 1];
//         if (distemp < dis[temp->x][temp->y + 1]) {
//           dis[temp->x][temp->y + 1] = distemp;
//           q.push(new Node(distemp, temp->x, temp->y + 1));
//         }
//       }
//       if (temp->x + 1 < m) {
//         int distemp = dis[temp->x][temp->y] + grid[temp->x + 1][temp->y];
//         if (distemp < dis[temp->x + 1][temp->y]) {
//           dis[temp->x + 1][temp->y] = distemp;
//           q.push(new Node(distemp, temp->x + 1, temp->y));
//         }
//       }
//       delete temp;
//     }
//     return dis[m - 1][n - 1];
//   }
// };

// DP
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (m == 1) {
      int ret = 0;
      for (int i = 0; i < n; i++) {
        ret += grid[0][i];
      }
      return ret;
    }
    for (int j = 1; j < n; j++) {
      grid[0][j] += grid[0][j - 1];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (j == 0) {
          grid[i][j] = grid[i - 1][j] + grid[i][j];
        } else {
          grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
      }
    }
    return grid[m - 1][n - 1];
  }
};
int main() {
  vector<vector<int>> grid;

  // vector<int> row1({1, 3, 1});
  // vector<int> row2({1, 5, 1});
  // vector<int> row3({4, 2, 1});
  vector<int> row1({1, 2});
  vector<int> row2({5, 6});
  vector<int> row3({1, 1});
  grid.push_back(row1);
  grid.push_back(row2);
  grid.push_back(row3);
  Solution a;
  cout << a.minPathSum(grid) << " =ans" << endl;
  // cout << a.minPathSum(grid) << " =ans" << endl;
  // cout << a.minPathSum(grid) << " =ans" << endl;
  return 0;
}
