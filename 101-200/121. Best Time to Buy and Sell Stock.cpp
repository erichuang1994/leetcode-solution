#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    vector<int> max(prices.size());
    int min = prices[0];
    int profit = 0;

    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] - min > profit) {
        profit = prices[i] - min;
      }
      if (prices[i] < min) {
        min = prices[i];
      }
    }
    return profit;
  }
};

int main() {}
