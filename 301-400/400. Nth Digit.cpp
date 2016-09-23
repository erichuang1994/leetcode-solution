#include <cmath>
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
  int findNthDigit(int n) {
    int num = 0;
    int width = 0;
    int left;
    if (n < 10) {
      return n;
    }
    while (n > 0) {
      width++;
      num = (n - 1) / width;
      left = n % width == 0 ? width : n % width;
      n = n - (pow(10, width) - pow(10, width - 1)) * width;
    }
    int cur =
        ((int)(pow(10, width - 1) + num) / (int)pow(10, width - left)) % 10;
    return cur;
  }
};
int main() {
  int n;
  cin >> n;
  Solution a;
  cout << a.findNthDigit(n) << endl;
}
