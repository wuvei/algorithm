class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] || obstacleGrid.back().back()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < n && !obstacleGrid[0][i]; ++i)
            dp[0][i] = 1;
        for (int i = 0; i < m && !obstacleGrid[i][0]; ++i)
            dp[i][0] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!obstacleGrid[i][j])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space Optimized
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);
        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j])
                    f[j] = 0;
                else if (j >= 1 && !obstacleGrid[i][j - 1]) {
                    f[j] += f[j - 1];
                }
            }
        }
        return f.back();
    }
};