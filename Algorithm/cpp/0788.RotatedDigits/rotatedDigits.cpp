class Solution {
public:
    constexpr static int diffs[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
    int rotatedDigits(int n) {
        auto s = to_string(n);
        int m = s.length();
        vector<vector<int> > dp(m, vector<int>(2, -1));
        function<int(int, bool, bool)> f;
        f = [&](int i, bool has_diff, bool is_limit) -> int {
            if (i == m) {
                return has_diff;
            }
            if (!is_limit && dp[i][has_diff] >= 0) {
                return dp[i][has_diff];
            }
            int res = 0, up = is_limit ? s[i] - '0' : 9;
            for (int d = 0; d <= up; ++d) {
                if (diffs[d] != -1) {// d is not 3/4/7
                    res += f(i + 1, has_diff || diffs[d], is_limit && d == up);
                }
            }
            if (!is_limit) {
                dp[i][has_diff] = res;
            }
            return res;
        };
        return f(0, false, true);
    }
};