class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

        for (int i = 0; i < strs.size(); ++i) {
            auto [count0, count1] = count(strs[i]);
            for (int j = m; j >= count0; --j) {
                for (int k = n; k >= count1; --k) {
                    dp[j][k] = std::max(dp[j][k], dp[j - count0][k - count1] + 1);
                }
            }
        }
        return dp[m][n];
    }

    pair<int, int> count(string &s) {
        int count0 = 0, count1 = 0;
        for(char c: s) {
            if (c == '0') count0++;
            else count1++;
        }
        return {count0, count1};
    }
};