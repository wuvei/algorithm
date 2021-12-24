class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int> > q, q2;
        auto p = getFirst(grid);
        q.push(p);
        q2.push(p);
        grid[p.first][p.second] = 2;
        int dir[5] = {1, 0, -1, 0, 1};
        while(!q2.empty()) {
            p = q2.front();
            q2.pop();
            for (int i = 0; i < 4; i++) {
                int x = p.first + dir[i], y = p.second + dir[i + 1];
                if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) continue;
                q2.push({x, y});
                q.push({x, y});
                grid[x][y] = 2;
            }
        }
        bool flag = false;
        int ans = 1;
        while (!flag && !q.empty()) {
            int len = q.size();
            for (int j = 0; j < len && !flag; j++) {
                p = q.front();
                q.pop();
                for (int i = 0; i < 4 && !flag; i++) {
                    int x = p.first + dir[i], y = p.second + dir[i + 1];
                    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 2) continue;
                    if (grid[x][y] == 1) {
                        flag = true;
                        break;
                    }
                    q.push({x, y});
                    grid[x][y] = 2;
                }
            }
            if(!flag) ans++;
        }
        return ans - 1;
    }

    pair<int, int> getFirst(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    return {i, j};
        return {-1, -1};
    }
};