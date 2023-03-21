class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        // split n
        vector<int> code;
        code.reserve(10);
        for (int t = n; t; t /= 10)
            code.push_back(t % 10);
        reverse(code.begin(), code.end());
        
        int m = code.size();
        vector<vector<int>> dp(m, vector<int>(1 << 10, -1));

        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m) return is_num;
            if (!is_limit && is_num && dp[i][mask] != -1)
                return dp[i][mask];
            int ans = 0;
            if (!is_num)
                ans = f(i + 1, mask, false, false);
            int up = is_limit ? code[i] : 9;
            for (int d = 1 - is_num; d <= up; ++d) {
                if ((mask >> d & 1) == 0)
                    ans += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            }
            if (!is_limit && is_num)
                dp[i][mask] = ans;
            return ans;
        };
        return n - f(0, 0, true, false);
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/numbers-with-repeated-digits/solutions/1748539/by-endlesscheng-c5vg/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。