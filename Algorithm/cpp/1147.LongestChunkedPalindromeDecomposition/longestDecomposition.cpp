class Solution {
public:
    int longestDecomposition(string s) {
        int ans = 0;
        while (!s.empty()) {
            int i = 1, n = s.length(), half = n >> 1;
            while (i <= half && s.substr(0, i) != s.substr(n - i)) // 枚举前后缀
                ++i;
            if (i > half) { // 无法分割
                ++ans;
                break;
            }
            ans += 2; // 分割出 s[:i] 和 s[n-i:]
            s = s.substr(i, n - i * 2);
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/solutions/2221544/tu-jie-tan-xin-zuo-fa-yi-tu-miao-dong-py-huik/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。