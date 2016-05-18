#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int countDigitOne(int n) {
    long long divisor = 10;
    long long bound = n;
    bound = 10 * bound;
    long long ret = 0;
    long long remain = 0;
    while (divisor <= bound) {
      ret += (n / divisor) * (divisor / 10);
      remain = n % divisor;
      if (remain >= divisor / 10) {
        int temp = remain - divisor / 10 + 1;
        ret += temp > divisor / 10 ? divisor / 10 : temp;
      }
      divisor = divisor * 10;
    }
    return ret;
  }
};
int main() {
  Solution a;
  cout << a.countDigitOne(824883294) << endl;
  return 0;
}
