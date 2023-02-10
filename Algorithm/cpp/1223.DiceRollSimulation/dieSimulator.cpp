class Solution {
    const long MOD = 1e9 + 7;
public:
    int dieSimulator(int n, vector<int> &rollMax) {
        int m = rollMax.size(), f[n][m][15];
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < rollMax[j]; ++k)
                f[0][j][k] = 1;
        for (int i = 1; i < n; ++i)
            for (int last = 0; last < m; ++last)
                for (int left = 0; left < rollMax[last]; ++left) {
                    long res = 0;
                    for (int j = 0; j < m; ++j)
                        if (j != last) res += f[i - 1][j][rollMax[j] - 1];
                        else if (left) res += f[i - 1][j][left - 1];
                    f[i][last][left] = res % MOD;
                }
        long ans = 0;
        for (int j = 0; j < m; ++j)
            ans += f[n - 1][j][rollMax[j] - 1];
        return ans % MOD;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/dice-roll-simulation/solutions/2103292/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-sje6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。