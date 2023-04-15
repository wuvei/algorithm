class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        auto visit = [&](int x, int y) {
            grid[x][y] = 2;
            q.push({x, y});
        };
        for (int i : {0, m - 1}) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    visit(i, j);
                }
            }
        }
        for (int i = 1; i < m - 1; ++i) {
            if (grid[i][0] == 1) visit(i, 0);
            if (grid[i][n - 1] == 1) visit(i, n - 1);
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i], ny = y + dir[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    visit(nx, ny);
            }
        }
        int ans = 0;
        for (int i = 1; i < m - 1; ++i)
            for (int j = 1; j < n - 1; ++j)
                ans += grid[i][j] == 1;
        return ans;
    }
};