class Solution {
public:
    int minRefuelStops(int t, int start, vector<vector<int>>& ss) {
        priority_queue<int> pq;
        int n = ss.size(), idx = 0;
        int remain = start, loc = 0, ans = 0;
        while (loc < t) {
            if (remain == 0) {
                if (!pq.empty() && ++ans >= 0) {
                    remain += pq.top();
                    pq.pop();
                }
                else return -1;
            }
            loc += remain;
            remain = 0;
            while (idx < n && ss[idx][0] <= loc) 
                pq.push(ss[idx++][1]);
        }
        return ans;
    }
};

// DP
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n + 1);
        dp[0] = startFuel;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/minimum-number-of-refueling-stops/solution/zui-di-jia-you-ci-shu-by-leetcode-soluti-nmga/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。