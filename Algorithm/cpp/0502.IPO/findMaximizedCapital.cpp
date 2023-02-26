class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) v[i] = std::make_pair(capital[i], profits[i]);
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int idx = 0;
        k = std::min(k, n);
        while (k--) {
            for (; idx < n && v[idx].first <= w; ++idx) pq.push(v[idx].second);
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};