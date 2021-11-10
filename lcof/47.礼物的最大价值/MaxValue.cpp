class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (!m || !n) return 0;
        int *dp = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = max((i == 0? 0: dp[j]), 
                (j == 0? 0: dp[j - 1])) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};