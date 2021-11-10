class Solution {
public:
    struct Node {
        int bx, by, px, py;        
    };
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'T') {
                    targetPos = {i, j};
                    grid[i][j] = '.';
                }
                else if (grid[i][j] == 'S') {
                    playerPos = {i, j};
                    grid[i][j] = '.';
                }
                else if (grid[i][j] == 'B') {
                    boxPos = {i, j};
                    grid[i][j] = '.';
                }
            }
        }
        int visited[21][21][21][21], push = 0;
        memset(visited, 0, sizeof(visited));
        queue<Node> q;
        visited[boxPos.first][boxPos.second][playerPos.first][playerPos.second] = 1;
        q.push({boxPos.first, boxPos.second, playerPos.first, playerPos.second});
        while (!q.empty()) {
            int size = q.size();
            push++;
            for (int i = 0; i < size; i++) {
                auto [bx, by, px, py] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nbx = bx + dir[j][0], nby = by + dir[j][1], rpx = bx - dir[j][0], rpy = by - dir[j][1];
                    if (nbx < 0 || nbx >= m || nby < 0 || nby >= n || rpx < 0 || rpx >= m || rpy < 0 || rpy >= n || grid[nbx][nby] == '#' || grid[rpx][rpy] == '#' || !reachable(grid, bx, by, px, py, rpx, rpy)) continue;
                    if (nbx == targetPos.first && nby == targetPos.second) return push;
                    if (!visited[nbx][nby][bx][by]) {
                        visited[nbx][nby][bx][by] = 1;
                        q.push({nbx,nby,bx,by});
                    }
                }
                
            }
        }
        return -1;
    }

    bool reachable(vector<vector<char>>& grid, int bx, int by, int px, int py, int rpx, int rpy) {
        if (px == rpx && py == rpy) return true;
        queue<pair<int, int> > q;
        int visited[21][21] = {};
        grid[bx][by] = '#';
        visited[px][py] = 1;
        q.push({px, py});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == '#') continue;
                if (nx == rpx && ny == rpy) {
                    grid[bx][by] = '.';
                    return true;
                }
                if (!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        grid[bx][by] = '.';
        return false;
    }
private:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    pair<int, int> targetPos, playerPos, boxPos;
};