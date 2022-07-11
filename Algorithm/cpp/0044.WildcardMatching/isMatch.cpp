class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size(), match = -1, star = -1;
        int i = 0, j = 0;
        while(i < m)
        {
            if(j < n && p[j] == '*') {
                match = i;
                star = j;
                ++j;
            }
            else if(j < n && (s[i] == p[j] || p[j]=='?')) {
                ++i;
                ++j;
            }
            else if(star >= 0) {
                i = match + 1;
                ++match;
                j = star + 1;
            }
            else
                return false;
        }
        while(j < n && p[j] == '*')
            j++;
        return (j==n);
    }
};

// DP
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            if (p[i - 1] == '*') dp[0][i] = true;
            else break;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};