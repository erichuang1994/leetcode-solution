#include <iostream>
#include <vector>
using namespace std;
// int r[1000];
// int nr[1000];n
class Solution {
public:
  int rob(vector<int> &nums) {
    int len = nums.size();
    if (len == 0)
      return 0;
    if (len == 1)
      return nums[0];
    else if (len == 2) {
      return max(nums[0], nums[1]);
    }
    // r[0] = nums[0];
    // r[1] = nums[1];
    // nr[0] = 0;
    // nr[1] = r[0];
    int r_1, r_2, nr;
    r_1 = nums[1];
    r_2 = nums[0];
    nr = nums[0];
    int temp;
    for (int i = 2; i < len; i++) {
      temp = r_1;
      r_1 = max(nr, r_2) + nums[i];
      nr = max(temp, nr);
      r_2 = temp;
    }
    return max(r_1, nr);
  }
};

int main() {
  Solution a;
  int v[] = {3, 2, 2, 4};
  vector<int> c(v, v + sizeof(v) / sizeof(v[0]));
  cout << a.rob(c) << endl;
  ;
}
