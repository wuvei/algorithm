class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int> > se;
        se.reserve(n);
        for (int i = 0; i < n; ++i) {
            se.push_back({efficiency[i], speed[i]});
        }
        sort(se.begin(), se.end(), greater<pair<int, int> >());
        priority_queue<int, vector<int>, greater<int> > pq;
        long long sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            int emin = se[i].first;
            sum += se[i].second;
            pq.push(se[i].second);
            ans = std::max(ans, emin * sum);
            if (i >= k - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return static_cast<int>(ans % 1000000007);
    }
};