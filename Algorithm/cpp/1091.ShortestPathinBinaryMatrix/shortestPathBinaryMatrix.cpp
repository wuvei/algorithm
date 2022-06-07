class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int, int> > q;
        q.push({0, 0});
        int ans = 1, dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<bool> > visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        for (; !q.empty(); ++ans) {
            int len = q.size();
            while(len--) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1)
                    return ans;
                for (int j = 0; j < 8; ++j) {
                    int nx = x + dir[j][0], ny = y + dir[j][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !visited[nx][ny]) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return -1;
    }
};