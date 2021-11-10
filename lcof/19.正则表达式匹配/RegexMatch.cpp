
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector< vector<bool> > dp(m, vector<bool>(n, false));
        dp[0][0] = true; // 两个空字符串能够匹配
        for (int j = 2; j < n; j++)
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        // 首行 s 为空字符串，因此当 p 的偶数位为 * 时才能够匹配（即让 p 的奇数位出现 0 次，保持 p 是空字符串）。因此，循环遍历字符串 p ，步长为 2（即只看偶数位）。
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = (p[j - 1] == '*')? dp[i][j - 2] || dp[i][j - 1] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')): dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Reference:
// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/jian-zhi-offer-19-zheng-ze-biao-da-shi-pi-pei-dong/