class Solution {
public:
    int bitCount(int a) {
        int ans = 0;
        while (a) {
            ++ans;
            a = a & (a - 1);
        }
        return ans;
    }
    int getCnt(int a, int b) {
        return bitCount(a) != bitCount(b) ? INF : bitCount(a ^ b) / 2;
    }
    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();
        unordered_set<int> r, c;
        for (int i = 0; i < n; ++i) {
            int row = 0, col = 0;
            for (int j = 0; j < n; ++j) {
                if (board[i][j]) row |= (1 << j);
                if (board[j][i]) col |= (1 << j);
            }
            r.insert(row);
            c.insert(col);
        }
        if (r.size() != 2 || c.size() != 2) return -1;
        vector<int> l1(r.begin(), r.end()), l2(c.begin(), c.end());
        int r1 = l1[0], r2 = l1[1], c1 = l2[0], c2 = l2[1], mask = (1 << n) - 1;
        if ((r1 ^ r2) != mask || (c1 ^ c2) != mask)  return -1;
        int i1 = 0, i2 = mask;
        for (int i = 0; i < n; i += 2) {
            i1 += (1 << i);
            i2 -= (1 << i);
        }
        int ans = std::min(getCnt(r2, i1), getCnt(r2, i2)) + std::min(getCnt(c2, i1), getCnt(c2, i2));
        return ans >= INF ? -1 : ans;
    }
private:
    int n, INF = 0x3f3f3f3f;
};