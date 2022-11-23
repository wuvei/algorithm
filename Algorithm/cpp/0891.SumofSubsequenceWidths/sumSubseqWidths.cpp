class Solution {
public:
    static constexpr int MOD = static_cast<int>(1e9) + 7;
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long p1 = nums[n - 1], p2 = nums[0], k = 1, sum = p1 - p2;
        for (int i = 1; i < n - 1; ++i) {
            k = (k << 1) % MOD;
            p1 += nums[n - i - 1];
            p2 += nums[i];
            long long temp = (k * ((p1 - p2) % MOD)) % MOD;
            sum = (sum + temp) % MOD;
        }
        return sum;
    }
};