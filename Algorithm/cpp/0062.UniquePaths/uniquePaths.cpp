// DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(2, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i & 1][j] = dp[(i - 1) & 1][j] + dp[i & 1][j - 1];
            }
        }
        return dp[(m - 1) & 1][n - 1];
    }
};

// Math
// https://leetcode.cn/problems/unique-paths/solution/bu-tong-lu-jing-by-leetcode-solution-hzjf/
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};