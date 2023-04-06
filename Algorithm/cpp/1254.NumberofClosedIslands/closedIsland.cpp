class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::function<void(int, int)> dfs = [&](int x, int y) {
            grid[x][y] = 2;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i], ny = y + dir[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    dfs(nx, ny);
                }
            }
        };
        // border
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) dfs(i, 0);
            if (i == 0 || i == m - 1) {
                for (int j = 1; j < n - 1; ++j)
                    if (grid[i][j] == 0) dfs(i, j);
            }
            if (grid[i][n - 1] == 0) dfs(i, n - 1);
        }
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    ++ans;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};