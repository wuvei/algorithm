class Solution {
public:
    string findTheString(vector<vector<int>> &lcp) {
        int i = 0, n = lcp.size();
        string s(n, 0);
        for (char c = 'a'; c <= 'z'; ++c) {
            while (i < n && s[i]) ++i;
            if (i == n) break; // 构造完毕
            for (int j = i; j < n; ++j)
                if (lcp[i][j]) s[j] = c;
        }
        while (i < n) if (s[i++] == 0) return ""; // 没有构造完

        // 直接在原数组上验证
        for (int i = n - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                int actualLCP = s[i] != s[j] ? 0 : i == n - 1 || j == n - 1 ? 1 : lcp[i + 1][j + 1] + 1;
                if (lcp[i][j] != actualLCP) return "";
            }
        return s;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/find-the-string-with-lcp/solutions/2120175/tan-xin-gou-zao-yan-zheng-o1e-wai-kong-j-82ik/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。