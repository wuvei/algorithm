class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] == b[1]? a[0] < b[0]: a[1] < b[1];
        });
        priority_queue<int> pq;
        int sum = 0;
        for (auto v: courses) {
            if (v[0] > v[1]) continue;
            if (sum + v[0] <= v[1]) {
                sum += v[0];
                pq.push(v[0]);
            }
            else if (!pq.empty() && pq.top() > v[0]) {
                sum += v[0] - pq.top();
                pq.pop();
                pq.push(v[0]);
            }
        }
        return pq.size();
    }
};