// BFS
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<vector<int> > q;
        vector<vector<int> > visit(m, vector<int>(n, -1));
        q.push({0, 0, k});
        visit[0][0] = k;
        int ans = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                auto v = q.front();
                q.pop();
                if (v[0] == m - 1 && v[1] == n - 1) {
                    return ans;
                }
                visit[v[0]][v[1]] = v[2]; 
                for (int j = 0; j < 4; ++j) {
                    int nx = v[0] + dir[j][0], ny = v[1] + dir[j][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if (grid[nx][ny]) {
                            if (visit[nx][ny] < v[2] - 1) {
                                q.push({nx, ny, v[2] - 1});
                                visit[nx][ny] = v[2] - 1;
                            }
                        }
                        else if (visit[nx][ny] < v[2]) {
                            q.push({nx, ny, v[2]});
                            visit[nx][ny] = v[2];
                        }
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};