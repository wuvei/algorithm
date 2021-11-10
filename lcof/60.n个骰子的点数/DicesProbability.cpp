class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> ans(5*n + 1);
        vector<int> dp(6*n + 1, 0);
        for (int i = 1; i <= 6; i++) dp[i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i*6; j >= 1; j--) {
                int temp = 0;
                for (int k = 1; k <= 6; k++) {
                    temp += j >= k? dp[j - k]: 0;
                }
                dp[j] = temp;
            }
        }
        int total = pow(6, n);
        for (int i = n; i <= 6*n; i++) ans[i - n] = 1.0 * dp[i] / total;
        return ans;
    }

    vector<double> dicesProbability(int n) {
        vector<double> dp(6*n + 1, 0);
        for (int i = 1; i <= 6; i++) dp[i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i*6; j >= 1; j--) {
                int temp = 0;
                for (int k = 1; k <= 6; k++) {
                    temp += j >= k? dp[j - k]: 0;
                }
                dp[j] = temp;
            }
        }
        int total = pow(6, n);
        for (int i = n; i <= 6*n; i++) dp[i] = 1.0 * dp[i] / total;
        return vector<double>(dp.begin() + n, dp.end());
    }
};