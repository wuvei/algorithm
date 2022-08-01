// DFS + memorize
class Solution {
public:
    int dfs(int x, int y, int maxMove) {
        if (x < 0 || x >= m || y < 0 || y >= n)
            return 1;
        if (x - maxMove >= 0 && x + maxMove < m && y - maxMove >= 0 && y + maxMove < n)
            return 0;
        if (cache[x][y][maxMove - 1] != -1)
            return cache[x][y][maxMove - 1];
        int ret = 0;
        for (int i = 0; i < 4; ++i) {
            ret += dfs(x + dir[i][0], y + dir[i][1], maxMove - 1) % 1000000007;
            ret %= 1000000007;
        }
        cache[x][y][maxMove - 1] = ret;
        return ret;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        cache.resize(m, vector<vector<int> >(n, vector<int>(maxMove, -1)));
        this -> m = m;
        this -> n = n;
        return dfs(startRow, startColumn, maxMove);
    }
private:
    vector<vector<vector<int> > > cache;
    int m, n, dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
};

// DP
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        int res = 0;
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    long up = (i == 0 ? 1 : dp[k - 1][i - 1][j]);
                    long down = (i == m - 1 ? 1 : dp[k - 1][i + 1][j]);
                    long left = (j == 0 ? 1 : dp[k - 1][i][j - 1]);
                    long right = (j == n - 1 ? 1 : dp[k - 1][i][j + 1]);
                    dp[k][i][j] = (up + down + left + right) % MOD;
                }
            }
        }

            return dp[maxMove][startRow][startColumn]; 
    }

private:
    const int MOD = 1000000007;
};
