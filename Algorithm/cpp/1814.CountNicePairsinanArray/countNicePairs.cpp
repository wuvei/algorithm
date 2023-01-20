class Solution {
public:
    const int MOD = static_cast<int>(1e9) + 7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int e: nums) {
            int t = e, rev = 0;
            while (t) {
                rev = rev * 10 + t % 10;
                t /= 10;
            }
            ++m[e - rev];
        }
        long long ans = 0;
        for (auto &it: m) {
            ans = (ans + (((it.second) * (it.second - 1LL)) >> 1)) % MOD;
        }
        return static_cast<int>(ans);
    }
};