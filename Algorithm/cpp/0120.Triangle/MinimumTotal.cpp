class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        int n = triangle.size(), pre1, pre2;
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            pre1 = dp[0];
            dp[0] = dp[0] + triangle[i][0];
            for(int j = 1; j < i; j++) {
                pre2 = dp[j];
                dp[j] = std::min(dp[j], pre1) + triangle[i][j];
                pre1 = pre2;
            }
            dp[i] = pre1 + triangle[i][i];
        }
        return *std::min_element(dp.begin(), dp.end());
    }
    

    int minimumTotal2(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        for(int i = n - 2; i >= 0; i--) 
            for(int j = 0; j <= i; j++) 
                triangle[i][j] += std::min(triangle[i + 1][j], t[i + 1][j + 1]); // chossing the optimal one
        
        return triangle[0][0];
    }
};