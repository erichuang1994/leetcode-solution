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
      ends = max(ends + nums[i], nums[i]);
      best = max(best, ends);
    }
    return best;
  }
};
// divide and conquer
class Solution {
public:
  void divideAndConquer(vector<int> &nums, int l, int r, int &sum, int &le,
                        int &re, int &cur) {
    if (l == r) {
      le = re = cur = sum = nums[l];
      return;
    }
    int mid = (l + r) / 2;
    int sum1, sum2, le1, le2, re1, re2, cur1, cur2;
    divideAndConquer(nums, l, mid, sum1, le1, re1, cur1);
    divideAndConquer(nums, mid + 1, r, sum2, le2, re2, cur2);
    le = max(le1, sum1 + le2);
    re = max(re2, sum2 + re1);
    sum = sum1 + sum2;
    cur = max({le, re, cur1, cur2, re1 + le2});
  }
  int maxSubArray(vector<int> &nums) {
    int sum, le, re, cur;
    divideAndConquer(nums, 0, nums.size() - 1, sum, le, re, cur);
    return cur;
  }
};
int main() {
  // Solution a;
  // int v = {};
  return 0;
}
