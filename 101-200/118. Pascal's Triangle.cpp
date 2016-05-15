#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret;
    if (numRows == 0)
      return ret;
    vector<int> row;
    row.push_back(1);
    ret.push_back(row);
    for (int i = 1; i < numRows; i++) {
      vector<int> temp;
      temp.push_back(1);
      for (int j = 0; j < i - 1; j++) {
        temp.push_back(ret[i - 1][j] + ret[i - 1][j + 1]);
      }
      temp.push_back(1);
      ret.push_back(temp);
    }
    return ret;
  }
};
int main() { return 0; }
