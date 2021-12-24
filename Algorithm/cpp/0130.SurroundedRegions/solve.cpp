class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        if (m <= 2 || n <= 2) return;
        queue<pair<int, int> > q;
        // borders
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') q.push({0, i});
            if (board[m - 1][i] == 'O') q.push({m - 1, i});
        }
        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][n - 1] == 'O') q.push({i, n - 1});
        }

        int dir[5] = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            board[r][c] = 'a';
            for (int i = 0; i < 4; i++) {
                int x = r + dir[i], y = c + dir[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                    q.push({x, y});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'a') board[i][j] = 'O';
            }
        }
    }
};