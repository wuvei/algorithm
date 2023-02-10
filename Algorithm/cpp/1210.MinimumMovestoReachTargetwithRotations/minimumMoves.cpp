class Solution {
    static constexpr int DIRS[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
public:
    int minimumMoves(vector<vector<int>> &g) {
        int n = g.size();
        bool vis[n][n][2];
        memset(vis, 0, sizeof(vis));
        vis[0][0][0] = true;
        vector<tuple<int, int, int>> q = {{0, 0, 0}}; // 初始位置
        for (int step = 1; !q.empty(); ++step) {
            vector<tuple<int, int, int>> nxt;
            for (const auto &[X, Y, S] : q) {
                for (const auto &d : DIRS) {
                    int x = X + d[0], y = Y + d[1], s = S ^ d[2];
                    int x2 = x + s, y2 = y + (s ^ 1); // 蛇头
                    if (x2 < n && y2 < n && !vis[x][y][s] &&
                        g[x][y] == 0 && g[x2][y2] == 0 && (d[2] == 0 || g[x + 1][y + 1] == 0)) {
                        if (x == n - 1 && y == n - 2) return step; // 此时蛇头一定在 (n-1,n-1)
                        vis[x][y][s] = true;
                        nxt.emplace_back(x, y, s);
                    }
                }
            }
            q = move(nxt);
        }
        return -1;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/minimum-moves-to-reach-target-with-rotations/solutions/2093126/huan-zai-if-elseyi-ge-xun-huan-chu-li-li-tw8b/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。