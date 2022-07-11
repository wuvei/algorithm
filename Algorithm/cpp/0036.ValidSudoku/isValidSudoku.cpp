class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > rows(9, vector<bool>(9, false)), cols(rows), sub(rows);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, temp = i / 3 * 3 +  j / 3;
                    if (rows[i][num]) return false;
                    else rows[i][num] = true;
                    if (cols[j][num]) return false;
                    else cols[j][num] = true;
                    if (sub[temp][num]) return false;
                    else sub[temp][num] = true;
                }
            }
        }
        return true;
    }
};