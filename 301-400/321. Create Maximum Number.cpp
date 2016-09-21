#include <deque>
#include <iostream>
#include <vector>
#define what_is(x) cerr << #x << " is " << x << endl
using namespace std;
class Solution {
public:
  bool compare(vector<int> &nums1, vector<int> &nums2, int last1, int last2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    while (last1 < len1 && last2 < len2) {
      if (nums1[last1] > nums2[last2]) {
        return true;
      }
      if (nums1[last1] < nums2[last2]) {
        return false;
      }
      last1++;
      last2++;
    }
    if (last1 < len1) {
      return true;
    }
    return false;
  }
  vector<int> genVec(vector<int> &nums, int k, vector<vector<int>> &dp) {
    vector<int> ret;
    if (k == 0) {
      return ret;
    }
    int len = nums.size();
    int max = len - k;
    int last = 0;
    while (k > 0) {
      last = dp[last][max] + 1;
      ret.push_back(nums[last - 1]);
      k--;
      max++;
    }
    return ret;
  }
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    vector<vector<int>> dp1(len1, vector<int>(len1));
    vector<vector<int>> dp2(len2, vector<int>(len2));
    for (int i = 0; i < len1; i++) {
      int max = nums1[i];
      int idx = i;
      for (int j = i; j < len1; j++) {
        if (nums1[j] > max) {
          max = nums1[j];
          idx = j;
        }
        dp1[i][j] = idx;
      }
    }
    for (int i = 0; i < len2; i++) {
      int max = nums2[i];
      int idx = i;
      for (int j = i; j < len2; j++) {
        if (nums2[j] > max) {
          max = nums2[j];
          idx = j;
        }
        dp2[i][j] = idx;
      }
    }
    vector<int> ret(k, 0);
    vector<int> tmp;
    for (int i = std::max(0, k - len2); i <= k && i <= len1; i++) {
      auto vec1 = genVec(nums1, i, dp1);
      auto vec2 = genVec(nums2, k - i, dp2);
      int x, y;
      x = y = 0;
      tmp.clear();
      for (; x < i && y < k - i;) {
        if (vec1[x] > vec2[y] ||
            (vec1[x] == vec2[y] && compare(vec1, vec2, x, y))) {
          tmp.push_back(vec1[x++]);
        } else {
          tmp.push_back(vec2[y++]);
        }
      }
      while (x < i) {
        tmp.push_back(vec1[x++]);
      }
      while (y < k - i) {
        tmp.push_back(vec2[y++]);
      }
      for (int i = 0; i < k; i++) {
        if (tmp[i] > ret[i]) {
          ret = tmp;
          break;
        } else if (tmp[i] < ret[i]) {
          break;
        }
      }
    }
    return ret;
  }
};
int main() {
  // vector<int> v1({6, 4, 7, 8, 6, 5, 5, 3, 1, 7, 4, 9, 9, 5, 9, 6, 1, 7,
  //                 1, 3, 6, 3, 0, 8, 2, 1, 8, 0, 0, 7, 3, 9, 3, 1, 3, 7,
  //                 5, 9, 4, 3, 5, 8, 1, 9, 5, 6, 5, 7, 8, 6, 6, 2, 0, 9,
  //                 7, 1, 2, 1, 7, 0, 6, 8, 5, 8, 1, 6, 1, 5, 8, 4});
  // vector<int> v2({3, 0, 0, 1, 4, 3, 4, 0, 8, 5, 9, 1, 5, 9, 4, 4, 4, 8,
  //                 0, 5, 5, 8, 4, 9, 8, 3, 1, 3, 4, 8, 9, 4, 9, 9, 6, 6,
  //                 2, 8, 9, 0, 8, 0, 0, 0, 1, 4, 8, 9, 7, 6, 2, 1, 8, 7,
  //                 0, 6, 4, 1, 8, 1, 3, 2, 4, 5, 7, 7, 0, 4, 8, 4});
  // vector<int> v1({3, 9});
  // vector<int> v2({8, 9});
  vector<int> v1({8, 5, 9, 5, 1, 6, 9});
  vector<int> v2({2, 6, 4, 3, 8, 4, 1, 0, 7, 2, 9, 2, 8});

  Solution a;
  // cout << a.maxNumber(v1, v2, 70).size() << endl;
  for (auto num : a.maxNumber(v1, v2, 20)) {
    cout << num << " ";
  }
  cout << endl;
}
