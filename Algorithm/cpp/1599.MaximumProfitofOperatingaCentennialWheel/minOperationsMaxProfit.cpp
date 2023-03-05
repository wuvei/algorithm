class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -2, maxP = 0, wait = 0, curP = 0;
        for (int i = 0; i < customers.size() || wait > 0; ++i) {
            wait += (i < customers.size() ? customers[i] : 0);
            int t = std::min(4, wait);
            wait -= t;
            curP += boardingCost * t - runningCost;
            if (curP > maxP) {
                maxP = curP;
                ans = i;
            }
        }
        return ans + 1;
    }
};