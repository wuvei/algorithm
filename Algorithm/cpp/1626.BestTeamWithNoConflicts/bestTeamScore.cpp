class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<int> dp(n, 0), idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return ages[a] == ages[b] ? scores[a] <= scores[b] : ages[a] < ages[b];
        });
        dp[0] = scores[idx[0]];
        int ans = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = scores[idx[i]];
            int t = -1;
            for (int j = 0; j < i; ++j) {
                if (scores[idx[j]] <= scores[idx[i]]) 
                    t = std::max(t, dp[j]);
            }
            if (t > 0) dp[i] += t;
            ans = std::max(dp[i], ans);
        }
        return ans;
    }
};