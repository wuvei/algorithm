class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), dp1 = 0, dp2 = 0;
        for (int i = 2; i < n; ++i) {
            int temp = min(dp1 + cost[i - 1], dp2 + cost[i - 2]);
            dp2 = dp1;
            dp1 = temp;
        }
        return min(dp1 + cost[n - 1], dp2 + cost[n - 2]);
    }
};