class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        vector<int> mask(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mask[i] |= mat[i][j] << j;
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            if (__builtin_popcount(i) == cols) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if ((mask[j] & i) == mask[j]) {
                        cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

// 作者：liu-xiang-3
// 链接：https://leetcode.cn/problems/maximum-rows-covered-by-columns/solution/c-by-liu-xiang-3-htvj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。