class Solution {
private:
  int lower, upper;
  int ret;

public:
  void mergeSort(vector<long long> &sums, int l, int r,
                 vector<long long> &tmp) {
    if (l == r) {
      if (lower <= sums[l] && sums[l] <= upper) {
        ret++;
      }
      return;
    }
    int mid = (l + r) / 2;
    mergeSort(sums, l, mid, tmp);
    mergeSort(sums, mid + 1, r, tmp);
    int p1, p2;
    p1 = p2 = mid;
    int x, y;
    x = r;
    while (x > mid) {
      while (p1 >= l && sums[x] - sums[p1] < this->lower) {
        p1--;
      }
      while (p2 >= l && sums[x] - sums[p2] <= this->upper) {
        p2--;
      }
      ret += p1 - p2;
      x--;
    }
    x = r;
    y = mid;
    for (int i = r; i >= l; i--) {
      if (x == mid) {
        while (y >= l) {
          tmp[i--] = sums[y--];
        }
      } else if (y == l - 1) {
        while (x >= mid + 1) {
          tmp[i--] = sums[x--];
        }
      } else {
        tmp[i] = sums[x] < sums[y] ? sums[y--] : sums[x--];
      }
    }
    for (int i = l; i <= r; i++) {
      sums[i] = tmp[i];
    }
  }
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    this->lower = lower;
    this->upper = upper;
    this->ret = 0;
    vector<long long> sums(nums.size(), 0);
    vector<long long> tmp(nums.size(), 0);
    int nums_len = sums.size();
    if (nums_len == 0) {
      return 0;
    }
    sums[0] = nums[0];
    for (int i = 1; i < nums_len; i++) {
      sums[i] = sums[i - 1] + nums[i];
    }
    mergeSort(sums, 0, sums.size() - 1, tmp);
    return ret;
  }
};
