class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), prev = 0, cur = 1;
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0] = matrix[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[cur][j] = dp[prev][j];
                if (j > 0) dp[cur][j] = std::min(dp[cur][j], dp[prev][j - 1]);
                if (j < n - 1) dp[cur][j] = std::min(dp[cur][j], dp[prev][j + 1]);
                dp[cur][j] += matrix[i][j];
            }
            std::swap(prev, cur);
        }
        return *min_element(dp[prev].begin(), dp[prev].end());
    }
};