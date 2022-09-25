class Solution {
public:
    const int MOD = static_cast<int>(1e9) + 7;
    int concatenatedBinary(int n) {
        long long ans = 0;
        int offset = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                ++offset;
            }
            ans = (ans << offset) % MOD;
            ans = ans + i;
        }
        return static_cast<int>(ans % MOD);
    }
};