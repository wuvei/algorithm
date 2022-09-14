class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        int n = quality.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return wage[i] * quality[j] < wage[j] * quality[i];
        });
        priority_queue<int> pq;
        int sum_q = 0;
        for (int i = 0; i < k; ++i) {
            pq.push(quality[id[i]]);
            sum_q += quality[id[i]];
        }
        double ans = sum_q * (1.0 * wage[id[k - 1]] / quality[id[k - 1]]);
        for (int i = k; i < n; ++i)
            if (int q = quality[id[i]]; q < pq.top()) { 
                sum_q -= pq.top() - q;
                pq.pop();
                pq.push(q);
                ans = min(ans, sum_q * (1.0 * wage[id[i]] / q));
            }
        return ans;
    }
};

// 作者：endlesscheng
// 链接：https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/solution/yi-bu-bu-ti-shi-ru-he-si-kao-ci-ti-by-en-1p00/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。