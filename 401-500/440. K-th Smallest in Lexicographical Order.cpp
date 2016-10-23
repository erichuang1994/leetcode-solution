class Solution {
public:
#define ll long long
  ll n, k, res;

  ll f(ll a, ll b, ll n) {
    ll res = 0;
    while (a < n) {
      a *= 10;
      b *= 10;
      res += max(0LL, min(n + 1, b) - a);
    }
    return res;
  }
  int findKthNumber(int n, int k) {
    ll res = 1;
    --k;
    while (k > 0) {
      if (k - 1 - f(res, res + 1, n) >= 0)
        k -= 1 + f(res, res + 1, n), ++res;
      else
        res *= 10, --k;
    }
    return res;
  }
};
