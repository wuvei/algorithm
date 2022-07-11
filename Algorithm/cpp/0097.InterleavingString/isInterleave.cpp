class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 + l2 != s3.size())
            return false;
        vector<bool> dp(l2 + 1, false);
        dp[0] = true;
        for (int i = 0; i <= l1; ++i) {
            for (int j = 0; j <= l2; ++j) {
                int idx = i + j - 1;
                if (i) dp[j] = (s1[i - 1] == s3[idx] && dp[j]);
                if (j && (!dp[j])) dp[j] = (s2[j - 1] == s3[idx] && dp[j - 1]);
            }
        }
        return dp[l2];
    }
};