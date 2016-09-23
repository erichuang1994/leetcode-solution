#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool dfs(vector<vector<char>> &board, int x, int y, int pos, string &word,
           vector<vector<bool>> &visited) {
    int dire[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    if (pos == word.size() - 1) {
      return true;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dire[i][0];
      int ny = y + dire[i][1];
      if (0 <= nx && nx < board.size() && 0 <= ny && ny < board[0].size()) {
        if (visited[nx][ny] == false && board[nx][ny] == word[pos + 1]) {
          visited[nx][ny] = true;
          if (dfs(board, nx, ny, pos + 1, word, visited))
            return true;
          visited[nx][ny] = false;
        }
      }
    }
    return false;
  }
  bool exist(vector<vector<char>> &board, string word) {
    if (word == "") {
      return true;
    }
    if (board.size() == 0) {
      return false;
    }
    vector<vector<bool>> visited(board.size(),
                                 vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          visited[i][j] = true;
          if (dfs(board, i, j, 0, word, visited))
            return true;
          visited[i][j] = false;
        }
      }
    }
    return false;
  }
};
int main() {}
