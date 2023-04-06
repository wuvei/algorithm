class Solution {
public:
    int minScoreTriangulation(vector<int> &v) {
        int n = v.size(), f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 3; i >= 0; --i)
            for (int j = i + 2; j < n; ++j) {
                f[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + v[i] * v[j] * v[k]);
            }
        return f[0][n - 1];
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/solutions/2203005/shi-pin-jiao-ni-yi-bu-bu-si-kao-dong-tai-aty6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。