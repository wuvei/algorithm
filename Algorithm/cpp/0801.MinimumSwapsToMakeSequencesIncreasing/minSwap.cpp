class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), cur, pre;
        vector<vector<int> > dp(2, vector<int>(2, 100005));
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < n; ++i) {
            cur = i & 1;
            pre = 1 ^ cur;
            dp[cur][0] = dp[cur][1] = 100005;
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                dp[cur][0] = min(dp[cur][0], dp[pre][1]);
                dp[cur][1] = min(dp[cur][1], dp[pre][0] + 1);
            }
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                dp[cur][0] = min(dp[cur][0], dp[pre][0]);
                dp[cur][1] = min(dp[cur][1], dp[pre][1] + 1);
            }
        }
        return min(dp[(n - 1) & 1][0], dp[(n - 1) & 1][1]);
    }
};