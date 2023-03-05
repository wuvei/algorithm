class Solution {
public:
    const int MOD = 1e9 + 7;
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= types.size(); ++i) {
            int cnt = types[i - 1][0], mark = types[i - 1][1];
            for (int j = target; j >= 0; --j) {
                long long res = dp[j];
                for (int k = 1, lim = std::min(cnt, j / mark); k <= lim; ++k) {
                    res += dp[j - k * mark];
                }
                dp[j] = res % MOD;
            }
        }
        return dp[target];
    }
};