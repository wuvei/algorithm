class Solution {
public:
    void backtracking(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 2) {
            if (count == 0) ++ans;
            return;
        }
        --count;
        int temp = grid[x][y];
        grid[x][y] = -1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i], ny = y + dir[i + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != -1) {
                backtracking(grid, nx, ny);
            }
        }
        ++count;
        grid[x][y] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) ++count;
                else if (grid[i][j] == 1)
                    start = std::make_pair(i, j);
            }
        }
        backtracking(grid, start.first, start.second);
        return ans;
    }
private:
    int m, n, ans = 0, count = 1, dir[5] = {1, 0, -1, 0, 1};
    pair<int, int> start;
};