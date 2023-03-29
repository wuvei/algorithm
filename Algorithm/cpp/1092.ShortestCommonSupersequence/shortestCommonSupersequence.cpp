class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1 = str1.size(), l2 = str2.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        string ans;
        ans.reserve(l1 + l2 - dp[l1][l2]);
        while (l1 || l2) {
            if (l1 == 0)
                ans += str2[--l2];
            else if (l2 == 0)
                ans += str1[--l1];
            else {
                if (dp[l1][l2] == dp[l1 - 1][l2])
                    ans += str1[--l1];
                else if (dp[l1][l2] == dp[l1][l2 - 1])
                    ans += str2[--l2];
                else
                    ans += str1[--l1], --l2;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};