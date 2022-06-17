class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector dp(n, 10010);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = i; j > 0; --j) {
                dp[j] = std::min(dp[j - 1], dp[j]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
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
