class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN, sell = 0;
        for(int p: prices) {
            buy = max(buy, sell - p - fee);
            sell = max(sell, buy + p);
        }
        return sell;
    }
};