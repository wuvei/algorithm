class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        const long long INF = 1e15;
        int n = robot.size(), m = factory.size();
    
        vector<vector<long long> > dp(m + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            const int pos = factory[i][0];
            const int lim = factory[i][1];
            dp[i + 1][0] = 0;
            for (int j = 0; j < n; ++j) {
                long long sum = 0;
                long long min_cost = dp[i][j + 1];
                for (int k = j; 0 <= k && j - lim < k; --k)
                    min_cost = min(min_cost, (sum += abs(robot[k] - pos)) + dp[i][k]);
                dp[i + 1][j + 1] = min_cost;
            }
        }
        return dp[m][n];
    }
};

// https://leetcode.cn/problems/minimum-total-distance-traveled/solutions/1952024/by-vclip-2wmo/