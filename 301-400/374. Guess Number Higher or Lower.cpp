// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    long long lo = 1;
    long long hi = n;
    long long mid;
    int tmp;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      tmp = guess(mid);
      switch (tmp) {
      case 1:
        lo = mid + 1;
        break;
      case -1:
        hi = mid - 1;
        break;
      case 0:
        return mid;
      }
    }
    return 0;
  }
};
