class Solution {
public:
    static const int MOD = 1000000007;
    int kInversePairs(int n, int k) {
        auto dp = vector<vector<long long> > (2, vector<long long>(k + 1, 0));
        dp[0][0] = dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            int bound = std::min(k, i * (i - 1) / 2);
            for (int j = 1; j <= bound; j++) {
                dp[i & 1][j] = (dp[i & 1][j - 1] + dp[(i - 1) & 1][j] - (j >= i ? dp[(i - 1) & 1][j - i] : 0) + MOD) % MOD;
            }
        }

        return (int) dp[n & 1][k];
    }

};