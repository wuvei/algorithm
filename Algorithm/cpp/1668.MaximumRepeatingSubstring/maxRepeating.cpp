class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), n2 = word.size();
        if (n < n2) return 0;
        vector<int> dp(n + 1, 0);
        int ans = 0;
        for (int i = n2; i <= n; ++i) {
            int k = n2 - 1;
            for (int j = i; k >= 0 && sequence[j - 1] == word[k]; --j, --k);
            if (k < 0) dp[i] = dp[i - n2] + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};