class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int dp[2]{};
        s[0] == 'a' ? dp[1] = 1 : dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'a') {
                dp[0] = dp[0];
                dp[1] = std::min(dp[1], dp[0]) + 1;
            } else {
                dp[1] = std::min(dp[1], dp[0]);
                dp[0] = dp[0] + 1;
            }
        }
        return std::min(dp[0], dp[1]);
    }
};

class Solution {
public:
    int minimumDeletions(string s) {
        int del = 0;
        for (char c : s)
            del += 'b' - c; // 统计 'a' 的个数
        int ans = del;
        for (char c : s) {
            // 'a' -> -1    'b' -> 1
            del += (c - 'a') * 2 - 1;
            ans = min(ans, del);
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/solutions/2149746/qian-hou-zhui-fen-jie-yi-zhang-tu-miao-d-dor2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。