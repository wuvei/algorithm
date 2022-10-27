class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<vector<long long> > info;
        int n = nums.size();
        long long total = 0;
        info.reserve(n);
        for (int i = 0; i < n; ++i) {
            info.push_back({nums[i], cost[i]});
            total += cost[i];
        }
        sort(info.begin(), info.end());
        long long cur = 0;
        for (int i = 1; i < n; ++i) {
            cur += info[i][1] * (info[i][0] - info[0][0]);
        }
        
        long long ans = cur, curTotal = info[0][1];
        for (int i = 0; i < n - 1; ++i) {
            cur += (info[i + 1][0] - info[i][0]) * (2 * curTotal - total);
            ans = std::min(ans, cur);
            curTotal += info[i + 1][1];
        }
        return ans;
    }
};