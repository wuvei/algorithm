class Solution {
    const int MOD = static_cast<int>(1e9) + 7;
public:
    int distinctSubseqII(string s) {
        int ans = 0;
        vector<int> f(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a', prev = f[c];
            f[c] = (ans + 1) % MOD;
            ans = (ans + f[c]) % MOD;
            ans = (ans - prev + MOD) % MOD;
        }
        return ans;
    }
};
