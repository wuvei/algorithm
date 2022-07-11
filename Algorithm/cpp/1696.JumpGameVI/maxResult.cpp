// DP + Monotonic Stack
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        deque<int> q;
        dp[0] = nums[0];
        q.push_back(0);
        for (int i = 1; i < n; ++i) {
            while (q.size() && i - q.front() > k)
                q.pop_front();
            dp[i] = dp[q.front()] + nums[i];
            while (q.size() && dp[i] > dp[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return dp[n - 1];
    }
};