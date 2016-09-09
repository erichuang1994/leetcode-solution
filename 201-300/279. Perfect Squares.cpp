class Solution {
public:
  int numSquares(int n) {
    static vector<int> res(1, 0);
    int tmp;
    if (res.size() <= n) {
      for (int i = res.size(); i <= n; i++) {
        if (pow(int(pow(i, 0.5)), 2) == i) {
          res.push_back(1);
          continue;
        }
        tmp = -1;
        for (int j = 1; j * j <= i; j++) {
          tmp = tmp == -1 ? res[i - j * j] + 1 : min(tmp, res[i - j * j] + 1);
        }
        res.push_back(tmp);
      }
    }
    return res[n];
  }
};
