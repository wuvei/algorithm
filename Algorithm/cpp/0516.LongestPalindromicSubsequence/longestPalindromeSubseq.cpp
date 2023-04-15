class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i] = 1;
            dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
        }
        dp[n - 1][n - 1] = 1;
        for (int len = 2; len < n; ++len) {
            for (int i = 0; i < n - len; ++i) {
                if (s[i] == s[i + len])
                    dp[i][i + len] = 2 + dp[i + 1][i + len - 1];
                else dp[i][i + len] = std::max(dp[i][i + len - 1], dp[i + 1][i + len]);
            }
        }
        return dp[0][n - 1];
    }
};