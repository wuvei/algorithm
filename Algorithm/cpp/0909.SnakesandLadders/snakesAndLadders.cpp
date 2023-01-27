class Solution {
public:
    int n;
    int getY(int a) {
        if (a / n & 1) {
            return n - 1 - a % n;
        }
        return a % n;
    }
    int snakesAndLadders(vector<vector<int>> &board) {
        n = board.size();
        int steps = 0, sq = n * n;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<int> qu;
        qu.push(1);
        vis[n - 1][0] = 1;

        while (!qu.empty()) {
            int sz = qu.size();
            for (int i = 0; i < sz; i++) {
                int coord = qu.front();
                qu.pop();

                if (coord == sq) return steps;

                for (int i = coord + 1; i <= coord + 6 && i <= sq; ++i) {
                    int new_row = n - 1 - (i - 1) / n, new_col = getY(i - 1);

                    if (vis[new_row][new_col]) continue;

                    vis[new_row][new_col] = 1;

                    if (board[new_row][new_col] != -1)
                        qu.push(board[new_row][new_col]);
                    else
                        qu.push(i);
                }
            }
            ++steps;
        }
        return -1;
    }
};