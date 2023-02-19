class Solution {
public:
    int minimumScore(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> prefix(m + 1), suffix(m + 1);
        for (int i = m - 1, j = n - 1; i >= 0; --i) {
            if (j >= 0 && s[i] == t[j]) {
                --j;
            }
            suffix[i] = n - j - 1;
        }
        if (suffix[0] == n) {
            return 0;
        }
        int ans = n - suffix[0];
        for (int i = 0, j = 0; i < m; ++i) {
            if (j < n && s[i] == t[j]) {
                ++j;
            }
            ans = min(ans, n - j - suffix[i + 1]);
        }
        return ans;
    }
};

// 作者：mike-meng
// 链接：https://leetcode.cn/problems/subsequence-with-the-minimum-score/solutions/2109075/mei-ju-qian-zhui-hou-zhui-de-zui-da-pi-p-lc06/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。