#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// DP
// For nums[n] to nums[n+1]
// T(nums[n+1]) = max(T(nums[n]),以T[n]结尾的最大值+T[n+1])
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int ends = nums[0];
    int best = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      best = max(max(best, ends + nums[i]), nums[i]);
      ends = max(ends + nums[i], nums[i]);
    }
    return best;
  }
};

int main() {
  // Solution a;
  // int v = {};
  return 0;
}
