class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 == 0) return n2;
        else if (n2 == 0) return n1;
        vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i <= n1; i++) {
            dp[i][0] = i;
            for (int j = 1; j <= n2; j++) {
                if (i == 0) dp[i][j] = j;
                else dp[i][j] = std::min({dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1]? 0: 1), dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            }
        }
        return dp[n1][n2];
    }
};