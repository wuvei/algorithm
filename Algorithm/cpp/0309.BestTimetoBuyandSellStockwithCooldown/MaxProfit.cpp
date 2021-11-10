class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, sell_pre = 0;
        for(int p: prices) {
            buy = max(buy, sell_pre - p);
            sell_pre = sell;
            sell = max(sell, buy + p);
        }
        return sell;
    }
};