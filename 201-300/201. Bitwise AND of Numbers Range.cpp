// my solution
class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    if (n == 0 && m == 0) {
      return 0;
    }
    return (rangeBitwiseAnd(m >> 1, n >> 1) << 1) + (m == n ? m & 1 : 0);
  }
};
// simpler solution
// class Solution {
// public:
//   int rangeBitwiseAnd(int m, int n) {
//     return n>m?rangeBitwiseAnd(m >> 1, n >> 1) << 1:n;
//   }
// };
