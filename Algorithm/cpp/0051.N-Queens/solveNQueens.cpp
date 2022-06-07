class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        ans.clear();
        if (n == 0) return ans;
        board.resize(n, string(n, '.'));
        column.resize(n, false);
        ldiag.resize(2*n-1, false);
        rdiag.resize(2*n-1, false);
        this -> n = n;
        backtracking(0);
        return ans;
    }

    void backtracking(int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (column[i] || ldiag[n-row+i-1] || rdiag[row+i]) continue;
            board[row][i] = 'Q';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = true;
            backtracking(row + 1);
            board[row][i] = '.';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
        }
    }
private:
    vector<bool> column, ldiag, rdiag;
    vector<string> board;
    vector<vector<string> > ans;
    int n;
};

// Backtrack + simulate
class Solution {
public:
    void change(int r, int c, char w) {
        char mark = '0' + r, others = (w == 'Q')? mark: '.';
        single[r][c] = w;
        for (int i = 0; i < 8; ++i) {
            int rr = r, cc = c;
            while ((rr = rr + dir[i][0]) >= 0 && rr < n && (cc = cc + dir[i][1]) >= 0 && cc < n) {
                if ((others == '.' && single[rr][cc] == mark) || (others == mark && single[rr][cc] == '.'))
                    single[rr][cc] = others;
            }
        }
    }
    void dfs(int r) {
        if (r == n) {
            vector<string> temp(single);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (temp[i][j] != 'Q')
                       temp[i][j] = '.';
                }
            }
            ans.push_back(std::move(temp));
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (single[r][i] == '.') {
                change(r, i, 'Q');
                dfs(r + 1);
                change(r, i, '.');
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this -> n = n;
        single.resize(n, string(n, '.'));
        dfs(0);
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> single;
    int dir[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, 0}, {1, -1}, {1, 1}};
    int n;
};