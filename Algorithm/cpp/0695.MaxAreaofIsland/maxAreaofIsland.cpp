class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    ans = std::max(ans, getArea(grid, i, j));
            }
        }
        return ans;
    }
    int getArea(vector<vector<int>>& grid, int x, int y) {
        int ans = 1;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < grid.size() && y1 >= 0 && y1 < grid[0].size() && grid[x1][y1] == 1 && !visited[x1][y1]) ans += getArea(grid, x1, y1);
        }
        return ans;
    }
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<bool> > visited;
};