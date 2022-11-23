class Solution {
public:
    static constexpr int MOD = static_cast<int>(1e9) + 7;
    int nthMagicalNumber(int n, int a, int b) {
        int c = std::lcm(a, b);
        long long l = 0, r = 1LL * min(a, b) * n;
        while (l < r) {
            long long mid = l + ((r - l) >> 1);
            if (mid / a + mid / b - mid / c >= n) r = mid;
            else l = mid + 1;
        }
        return static_cast<int>(l % MOD);
    }
};