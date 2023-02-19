class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> left(grid), up(grid);
        // calculate # of continuous 1s
        for (int i = 1; i < n; ++i)
            if (grid[0][i] == 1) left[0][i] = left[0][i - 1] + 1;
        for (int i = 1; i < m; ++i)
            if (grid[i][0] == 1) up[i][0] = up[i - 1][0] + 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                left[i][j] = left[i][j - 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = std::min(left[i][j], up[i][j]);
                while (k) {
                    if (left[i - k + 1][j] >= k && up[i][j - k + 1] >= k) {
                        ans = std::max(ans, k);
                        break;
                    }
                    --k;
                }
            }
        }
        return ans * ans;
    }
};