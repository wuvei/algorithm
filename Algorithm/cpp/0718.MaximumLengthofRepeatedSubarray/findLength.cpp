class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, len1 = nums1.size(), len2 = nums2.size(), upleft, temp;
        vector <int> dp(len2 + 1, 0);
        for (int i = 1; i <= len1; i++) {
            upleft = dp[0];
            for (int j = 1; j <= len2; j++) {
                temp = dp[j];
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = upleft + 1;
                    ans = std::max(ans, dp[j]);
                }
                else dp[j] = 0;
                upleft = temp;
            }
        }
        
        return ans;
    }
};