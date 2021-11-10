class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int> > child(n + 1, vector<int>());
        vector<int> count(n + 1, 0), start_time(n + 1, 0);
        queue<int> q;
        for (auto v: relations) {
            child[v[0]].push_back(v[1]);
            count[v[1]]++;
        }
        int min_time = 0;
        for (int i = 1; i <= n; i++)
            if (!count[i]) {
                q.push(i);
                min_time = std::max(time[i - 1], min_time);
            }
        
        while(!q.empty()) {
            int size = q.size(), temp = 0;
            while (size--) {
                int course = q.front(), finish_time = start_time[course] + time[course - 1];
                q.pop();
                for (auto c: child[course]) {
                    count[c]--;
                    if (!count[c]) q.push(c);
                    start_time[c] = std::max(start_time[c], finish_time);
                }
                min_time = std::max(finish_time, min_time);
            }
        }
        return min_time;
    }
};