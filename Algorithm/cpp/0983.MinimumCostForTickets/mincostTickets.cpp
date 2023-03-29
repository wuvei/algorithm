class Solution {
public:
    const int d[3]{1, 7, 30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), 1e6);
        for (int i = 0; i < days.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                if (days[0] > days[i] - d[j])
                    dp[i] = std::min(dp[i], costs[j]);
                else {
                    int idx = std::upper_bound(days.begin(), days.begin() + i, days[i] - d[j]) - days.begin();
                    dp[i] = std::min(dp[i], costs[j] + dp[idx - 1]);
                } 

            }
        }
        return dp.back();
    }
};