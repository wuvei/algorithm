class Solution {
public:
    static constexpr int MOD = static_cast<int>(1e9) + 7;
    int countHomogenous(string s) {
        long long ans = s.length(), cur = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) ++cur;
            else if (cur > 1) {
                ans = (ans + (((cur - 1) * cur) >> 1)) % MOD;
                cur = 1;
            }
        }
        if (cur > 1) {
            ans = (ans + (((cur - 1) * cur) >> 1)) % MOD;
        }
        return ans;
    }
};