class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = std::accumulate(nums.begin(), nums.end(), 0);
        if (target & 1) return false;
        int n = nums.size();
        target = target >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= nums[i - 1]; j--) {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};