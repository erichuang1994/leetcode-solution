#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    int indexs[primes.size()];
    int nums[n];
    for (int i = 0; i < primes.size(); i++) {
      indexs[i] = 0;
    }
    nums[0] = 1;
    for (int i = 1; i < n; i++) {
      int temp = 0;
      int tempNum = -1;
      if (nums[indexs[0]] * primes[0] == nums[i - 1]) {
        indexs[0]++;
      }
      temp = 0;
      tempNum = nums[indexs[0]] * primes[0];
      for (int j = 1; j < primes.size(); j++) {
        if (nums[indexs[j]] * primes[j] == nums[i - 1]) {
          indexs[j]++;
        }
        if (nums[indexs[j]] * primes[j] < tempNum) {
          temp = j;
          tempNum = nums[indexs[j]] * primes[j];
        }
      }
      indexs[temp]++;
      nums[i] = tempNum;
    }
    return nums[n - 1];
  }
};

int main() {
  Solution a;
  int v[] = {2, 3, 7, 13, 17, 23, 31, 41, 43, 47};
  vector<int> b(v, v + sizeof(v) / sizeof(v[0]));
  cout << a.nthSuperUglyNumber(45, b) << endl;
  return 0;
}
