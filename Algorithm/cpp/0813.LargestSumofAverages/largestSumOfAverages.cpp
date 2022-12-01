class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<vector<double>> dp(k + 1, vector<double>(n, 0));
        prefix[0] = dp[1][0] = nums[0];
        for(int i = 1; i < n; ++i){
            prefix[i] = prefix[i - 1] + nums[i];
            dp[1][i] = 1.0 * prefix[i] / (i + 1);
        }
        
        for(int part = 2; part <= k; ++part){
            for(int i = part - 1; i < n; ++i){
                for(int j = part - 2; j < i; ++j){
                    dp[part][i] = max(dp[part][i], dp[part - 1][j] + double(prefix[i] - prefix[j]) / (i - j) );
                }
                
            }
        }
        return dp[k][n - 1];
    }
};