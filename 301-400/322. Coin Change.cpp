class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    if (n == 0)
      return -1;
    if (amount == 0)
      return 0;
    int c[amount + 1];
    for (int i = 0; i < amount + 1; i++) {
      c[i] = 99999;
    }
    for (auto i : coins) {
      if (i <= amount) {
        c[i] = 1;
      }
    }
    c[0] = 0;
    for (int i = 0; i <= amount; i++) {
      for (auto j : coins) {
        if (i + j <= amount) {
          c[i + j] = c[i + j] > c[i] + 1 ? c[i] + 1 : c[i + j];
        }
      }
    }
    if (c[amount] == 99999) {
      return -1;
    } else {
      return c[amount];
    }
  }
};

int main() {
  Solution a;
  int v[] = {384, 324, 196, 481};
  vector<int> b(v, v + sizeof(v) / sizeof(v[0]));
  cout << a.coinChange(b, 285) << endl;
}
