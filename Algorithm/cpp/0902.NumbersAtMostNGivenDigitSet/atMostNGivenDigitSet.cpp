class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int len = s.size();
        vector<int> dp(len, -1);
        function<int(int, bool, bool)> f = [&](int idx, bool lead0, bool is_limit) -> int {
            if (idx == len) return !lead0;
            if (!is_limit && !lead0 && dp[idx] >= 0) return dp[idx];
            int ans = 0;
            if (lead0)
                ans += f(idx + 1, true, false);

            for (auto &d: digits) {
                if (is_limit && d[0] > s[idx]) break;
                ans += f(idx + 1, false, is_limit && d[0] == s[idx]);
            }
            if (!lead0 && !is_limit) dp[idx] = ans;
            return ans;
        };
        return f(0, true, true);
    }
};