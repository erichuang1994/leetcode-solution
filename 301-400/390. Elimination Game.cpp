#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int lastRemaining(int n) {
    int left, right;
    int bias = 2;
    left = 1;
    right = n;
    int turn = 0;
    while (left < right) {
      if (turn % 2 == 0) {
        if ((right - left) % bias == 0) {
          right = right - bias / 2;
        }
        left = left + bias / 2;
      } else {
        if ((right - left) % bias == 0) {
          left = left + bias / 2;
        }
        right = right - bias / 2;
      }
      turn++;
      bias *= 2;
    }
    return left;
  }
};
int main() {
  Solution a;
  int n;
  cin >> n;
  cout << a.lastRemaining(n) << endl;
}
