class Solution {
public:
    using pii = pair<int, int>;
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        std::stable_sort(time.begin(), time.end(), [](auto &a, auto &b) {
            return a[0] + a[2] < b[0] + b[2];
        });
        priority_queue<pii> waitL, waitR;
        priority_queue<pii, vector<pii>, greater<> > workL, workR;
        for (int i = 0; i < k; ++i) waitL.emplace(i, 0);
        int cur = 0;
        while (n) {
            // workers on the left finish moving boxes
            while (!workL.empty() && workL.top().first <= cur) {
                auto [t, i] = workL.top();
                workL.pop();
                waitL.emplace(i, t);
            }
            // workers on the right finish moving boxes
            while (!workR.empty() && workR.top().first <= cur) {
                auto [t, i] = workR.top();
                workR.pop();
                waitR.emplace(i, t);
            }
            // workers on the right go first.
            if (!waitR.empty() && waitR.top().second <= cur) {
                auto [i, t] = waitR.top();
                waitR.pop();
                cur += time[i][2];
                workL.emplace(cur + time[i][3], i);
            }
            else if (!waitL.empty() && waitL.top().second <= cur) {
                auto [i, t] = waitL.top();
                waitL.pop();
                cur += time[i][0];
                workR.emplace(cur + time[i][1], i);
                --n;
            }
            // All are busy, wait
            else if (workL.empty()) cur = workR.top().first;
            else if (workR.empty()) cur = workL.top().first;
            else cur = std::min(workL.top().first, workR.top().first);
        }
        while (!workR.empty()) {
            auto [t, i] = workR.top();
            workR.pop();
            cur = std::max(cur, t) + time[i][2];
        }
        return cur;
    }
};