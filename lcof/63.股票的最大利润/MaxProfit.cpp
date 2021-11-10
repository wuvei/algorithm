class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int prevMin = prices[0], profit = 0;
        for (int p: prices) {
            if (prevMin > p) prevMin = p;
            else {
                profit = std::max(p - prevMin, profit);
            }
        }
        return profit;
    }
};