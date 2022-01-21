class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 1) return 1;
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), 1);
        for (int i = pairs.size() - 2; i >= 0; --i) {
            auto it = std::lower_bound(pairs.begin() + i + 1, pairs.end(), vector<int>{pairs[i][1] + 1, -1001});
            if (it != pairs.end()) dp[i] = dp[it - pairs.begin()] + 1;
            dp[i] = std::max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};