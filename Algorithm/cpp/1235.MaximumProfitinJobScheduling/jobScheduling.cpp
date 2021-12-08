class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int> > zipped;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            zipped.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(zipped.begin(), zipped.end());
        vector<int> dp(n, zipped[n - 1][2]);
        for (int i = n - 2; i >= 0; i--) {
            auto it = std::lower_bound(zipped.begin() + i + 1, zipped.end(), vector<int>({zipped[i][1], 0, 0}));
            int temp = 0;
            if (it != zipped.end()) temp = dp[int(it - zipped.begin())];
            dp[i] = std::max(dp[i + 1], temp + zipped[i][2]);
        }
        return dp[0];
    }
};