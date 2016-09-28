#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> lexicalOrder(int n) {
    int i = 0;
    int cur = 1;
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
      ret[i] = cur;
      if (cur * 10 <= n) {
        cur *= 10;
      } else if (cur + 1 <= n && cur % 10 != 9) {
        cur++;
      } else {
        while ((cur / 10) % 10 == 9) {
          cur /= 10;
        }
        cur /= 10;
        cur++;
      }
    }
    return ret;
  }
};
int main() {
  Solution a;
  for (auto n : a.lexicalOrder(10)) {
    cout << n << " ";
  }
  cout << endl;
}
