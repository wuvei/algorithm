class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dis(m, vector<int>(n, 300));
        queue<pair<int, int> > q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) continue;
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
        if (q.size() == m * n) return -1;
        int ans = 0, dir[] = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                auto [x, y] = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = x + dir[j], ny = y + dir[j + 1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && dis[nx][ny] > ans) {
                        dis[nx][ny] = ans;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ans - 1;
    }
};