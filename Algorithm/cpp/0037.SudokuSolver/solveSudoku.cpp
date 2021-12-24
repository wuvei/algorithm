class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    rows[i][val] = cols[j][val] = subbox[i / 3 * 3 + j / 3][val] = 1;
                }
            }
        }
        backtracking(board, 0, 0);
    }

    bool backtracking(vector<vector<char>>& board, int x, int y) {
        for (int i = x; i < 9; i++) {
            int j = i == x? y: 0;
            for (; j < 9; j++) {
                if (board[i][j] != '.') continue;
                for (int k = 1; k <= 9; k++) {
                    if (rows[i][k] == 1 || cols[j][k] == 1 || subbox[i / 3 * 3 + j / 3][k] == 1) continue;
                    board[i][j] = '0' + k;
                    rows[i][k] = cols[j][k] = subbox[i / 3 * 3 + j / 3][k] = 1;
                    if (backtracking(board, j == 8? i + 1: i, j == 8? 0: j + 1))
                        return true;
                    board[i][j] = '.';
                    rows[i][k] = cols[j][k] = subbox[i / 3 * 3 + j / 3][k] = 0;
                }
                return false;
            }
        }
        return true;
    }
private:
    int rows[9][10] = {}, cols[9][10] = {}, subbox[9][10] = {};
};