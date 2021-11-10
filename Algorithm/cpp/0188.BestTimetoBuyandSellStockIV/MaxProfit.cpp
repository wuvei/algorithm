class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int length = prices.size();
        if (length <= 1 || !k) return 0;
        if (k >= length >> 1) {
            int profit = 0;
            for (int i = 1; i < length; i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        for (int i = 0; i < length; i++) {
            for (int j = 1; j <= k; j++) {
                buy[j] = std::max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = std::max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};