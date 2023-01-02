class Solution {
  using PII = pair<int, int>;
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = size(tasks);
    vector<int> t(n);
    iota(t.begin(), t.end(), 0);
    sort(t.begin(), t.end(), [&](int a, int b) {
        if (tasks[a][0] != tasks[b][0]) return tasks[a][0] < tasks[b][0];
        else return tasks[a][1] < tasks[b][1];
    });

    vector<int> ans;
    ans.reserve(n);
    int cpu_last{};
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    for (int i : t) {
        auto [start, cost] = (int(&)[2])tasks[i][0];
        while (start > cpu_last) {
            if (pq.empty()) break;
            auto [span, order]{pq.top()};
            cpu_last = max(cpu_last, tasks[order][0]) + span;
            ans.emplace_back(order);
            pq.pop();
        }
        pq.push({cost, i});
    }
    while (!pq.empty()) {
        auto [cost, i] {pq.top()};
        ans.emplace_back(i);
        pq.pop();
    }
    return ans;
  }
};