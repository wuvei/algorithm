class Solution {
public:
    int f(int l, int r, int compensation) {
        int res = s[r] + s[l - 1] - s[(l + r) / 2] * 2;
        if((r - l) % 2 == 0) res += compensation;
        return res;
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        s.resize(n+1);
        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + houses[i - 1];
        dp.resize(n+1, 10000000);
        dp[0] = 0;
        for (int i = 1; i <= k; i++) {
            for(int j = n; j >= 1; j --) {
                for (int p = 0; p < j; p++) {
                    dp[j] = std::min(dp[j], dp[p] + f(p + 1, j, houses[(p+1+j)/2 - 1]));
                }
            }
        }
        return dp[n];
    }
private:
    vector<int> s, dp;
};