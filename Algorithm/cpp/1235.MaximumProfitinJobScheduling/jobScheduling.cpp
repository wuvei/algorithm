class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int> > zipped;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            zipped.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(zipped.begin(), zipped.end());
        vector<int> dp(n, zipped[n - 1][2]);
        for (int i = n - 2; i >= 0; i--) {
            auto it = std::lower_bound(zipped.begin() + i + 1, zipped.end(), vector<int>({zipped[i][1], 0, 0}));
            int temp = 0;
            if (it != zipped.end()) temp = dp[int(it - zipped.begin())];
            dp[i] = std::max(dp[i + 1], temp + zipped[i][2]);
        }
        return dp[0];
    }
};

class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int n = startTime.size();
        array<int, 3> jobs[n];
        for (int i = 0; i < n; ++i)
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        sort(jobs, jobs + n, [](auto &a, auto &b) { return a[0] < b[0]; });

        int f[n + 1];
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int j = upper_bound(jobs, jobs + i, array<int, 3>{jobs[i][1], INT_MAX}) - jobs;
            f[i + 1] = max(f[i], f[j] + jobs[i][2]);
        }
        return f[n];
    }
};

// 作者：endlesscheng
// 链接：https://leetcode.cn/problems/maximum-profit-in-job-scheduling/solution/dong-tai-gui-hua-er-fen-cha-zhao-you-hua-zkcg/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。