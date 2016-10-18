class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) {
      return 0;
    }
    int low = prices[0], best = 0;
    for (int i = 1; i < prices.size(); ++i) {
      best = max(prices[i] - low, best);
      low = min(low, prices[i]);
    }
    return best;
  }
};
