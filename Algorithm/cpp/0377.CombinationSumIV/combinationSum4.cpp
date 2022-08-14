class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int val: nums) {
                if (i - val >= 0 && dp[i] < INT_MAX - dp[i - val]) 
                    dp[i] += dp[i - val];
            }
        }
        return dp[target];
    }
};