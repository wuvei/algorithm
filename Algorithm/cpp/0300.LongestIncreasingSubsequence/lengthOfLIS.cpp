// Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis({nums[0]});
        for (int e: nums) {
            if (lis.back() < e) lis.push_back(e);
            else {
                auto it = lower_bound(lis.begin(), lis.end(), e);
                *it = e;
            }
        }
        return lis.size();
    }
};

// DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
             ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};