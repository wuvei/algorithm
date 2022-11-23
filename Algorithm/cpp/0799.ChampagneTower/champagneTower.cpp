class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(query_row + 2, 0);
        dp[0] = poured;
        for (int i = 0; i < query_row; ++i) {
            for (int j = std::min(i, query_glass); j >= 0; --j) {
                double t = std::max(0.0, dp[j] - 1) / 2.0;
                dp[j] = t;
                dp[j + 1] += t;
            }
        }
        return std::min(1.0, dp[query_glass]);
    }
};