#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool flag[9];
    // check row
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        flag[j] = false;
      }
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          if (flag[board[i][j] - '1']) {
            return false;
          }
          flag[board[i][j] - '1'] = true;
        }
      }
    }
    // check col
    for (int j = 0; j < 9; j++) {
      for (int i = 0; i < 9; i++) {
        flag[i] = false;
      }
      for (int i = 0; i < 9; i++) {
        if (board[i][j] != '.') {
          if (flag[board[i][j] - '1']) {
            return false;
          }
          flag[board[i][j] - '1'] = true;
        }
      }
    }
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        for (int l = 0; l < 9; l++) {
          flag[l] = false;
        }
        for (int x = i; x < i + 3; x++) {
          for (int y = j; y < j + 3; y++) {
            if (board[x][y] != '.') {
              if (flag[board[x][y] - '1']) {
                return false;
              }
              flag[board[x][y] - '1'] = true;
            }
          }
        }
      }
    }
    return true;
  }
};

int main() {
  Solution a;
  // int v = {};
  return 0;
}
