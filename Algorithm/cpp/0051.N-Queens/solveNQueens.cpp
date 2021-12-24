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