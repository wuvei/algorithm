class Solution {
    int n, m;
    const int MOD = 1000000007;

public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        n = grid.size(); m = grid[0].size();

        long long f[n][m][K];
        memset(f, 0, sizeof(f));
        f[0][0][grid[0][0] % K] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < K; k++) {
                    if (i > 0) 
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j][(k - grid[i][j] % K + K) % K]) % MOD;

                    if (j > 0) 
                        f[i][j][k] = (f[i][j][k] + f[i][j - 1][(k - grid[i][j] % K + K) % K]) % MOD;
                }
            }
        }
        return f[n - 1][m - 1][0];
    }
};

// 作者：tsreaper
// 链接：https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/solution/by-tsreaper-mejx/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。