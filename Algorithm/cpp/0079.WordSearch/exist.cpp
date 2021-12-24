class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        this -> word = word;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtracking(board, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, int r, int c, int idx) {
        if (board[r][c] != word[idx]) return false;
        if (idx == word.size() - 1) return true;
        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int x = r + dir[i], y = c + dir[i + 1];
            bool flag = false;
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) flag = backtracking(board, x, y, idx + 1);
            if (flag) return true;
        }
        visited[r][c] = false;
        return false;
    }
private:
    string word;
    vector<vector<bool> > visited;
    int dir[5] = {1, 0, -1, 0, 1}, m, n;
};