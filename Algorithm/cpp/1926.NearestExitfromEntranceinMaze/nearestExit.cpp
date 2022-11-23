class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        bool if_start = true;
        auto f = [&]() -> bool {
            auto [x, y] = q.front();
            q.pop();
            if ((x == 0 || y == 0 || x == m - 1 || y == n - 1) && !if_start)
                return true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.' && !visit[nx][ny]) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
            return false;
        };
        int ans = 1;
        q.push({entrance[0], entrance[1]});
        visit[entrance[0]][entrance[1]] = true;
        f();
        if_start = false;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                if (f()) return ans;
            }
            ++ans;
        }
        return -1;
    }
};