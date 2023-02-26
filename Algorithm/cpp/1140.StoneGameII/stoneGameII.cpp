class Solution {
public:
    int stoneGameII(vector<int> &piles) {
        int s = 0, n = piles.size(), f[n][n / 2 + 2];
        for (int i = n - 1; i >= 0; --i) {
            s += piles[i];
            for (int m = 1; m <= i / 2 + 1; ++m) {
                if (i + m * 2 >= n) f[i][m] = s;
                else {
                    int mn = INT_MAX;
                    for (int x = 1; x <= m * 2; ++x)
                        mn = min(mn, f[i + x][max(m, x)]);
                    f[i][m] = s - mn;
                }
            }
        }
        return f[0][1];
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/stone-game-ii/solutions/2125753/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-jjax/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。