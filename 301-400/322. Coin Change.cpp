#include <iostream>
#include <vector>
using namespace std;
int flag[1000000];
int c[1000000];
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    for (int i = 0; i <= amount; ++i) {
      flag[i] = false;
      c[i] = 999999;
    }
    for (auto i : coins) {
      flag[i] = true;
      c[i] = 1;
    }
    flag[0] = true;
    c[0] = 0;
    for (int i = 0; i <= amount; i++) {
      if (flag[i] == true) {
        for (auto j : coins) {
          flag[i + j] = true;
          c[i + j] = c[i + j] > c[i] + 1 ? c[i] + 1 : c[i + j];
        }
      }
    }
    return flag[amount] == false ? -1 : c[amount];
  }
};

int main() {
  Solution a;
  int v[] = {384, 324, 196, 481};
  vector<int> b(v, v + sizeof(v) / sizeof(v[0]));
  cout << a.coinChange(b, 285) << endl;
}
