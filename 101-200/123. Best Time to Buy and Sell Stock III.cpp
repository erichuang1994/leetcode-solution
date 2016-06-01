#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0)
      return 0;
    vector<int> bte(prices.size());
    vector<int> etb(prices.size());
    int min = prices[0];
    int maxprofit = 0;
    int len = prices.size();
    for (int i = 0; i < len; i++) {
      if (prices[i] - min > maxprofit) {
        maxprofit = prices[i] - min;
      } else if (prices[i] < min) {
        min = prices[i];
      }
      bte[i] = maxprofit;
    }
    int max = prices[prices.size() - 1];
    maxprofit = 0;
    for (int i = len - 1; i >= 0; i--) {
      if (max - prices[i] > maxprofit) {
        maxprofit = max - prices[i];
      } else if (prices[i] > max) {
        max = prices[i];
      }
      etb[i] = maxprofit;
    }
    int ret = bte[len - 1];
    for (int i = 0; i < len - 1; i++) {
      ret = bte[i] + etb[i + 1] > ret ? bte[i] + etb[i + 1] : ret;
    }
    return ret;
  }
};

int main() {
  Solution a;
  // int v = {};
  return 0;
}
