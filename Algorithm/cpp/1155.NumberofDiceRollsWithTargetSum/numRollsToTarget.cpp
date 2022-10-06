// Memorize
class Solution {
public:
    const int mod = static_cast<int>(1e9) + 7;
    int k;
    vector<vector<int> > dp;
    int f(int n, int t) {
        if (dp[n][t] != -1) {
            return dp[n][t];
        }
        long long temp = 0;
        for (int i = 1; i <= k && i <= t + 1 - n; ++i) {
            temp = (temp + f(n - 1, t - i)) % mod;
        }
        return dp[n][t] = static_cast<int>(temp);
    }
    int numRollsToTarget(int n, int k, int target) {
        this->k = k;
        dp.resize(n + 1, vector<int>(target + 1, -1));
        for (int i = 1; i <= target; ++i) {
            if (i <= k) {
                dp[1][i] = 1;
            }
            dp[0][i] = 0;
        }
        return f(n, target);
    }
};

// Backpack DP
class Solution {
public:
    const int mod = static_cast<int>(1e9) + 7;
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++)
            for (int j = 1; j <= target; j++)
                for (int k = 1; k <= f && j >= k; k++)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
        return dp[d][target];
    }
};
// 作者：eh-xing-qing
// 链接：https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-rsy8/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。