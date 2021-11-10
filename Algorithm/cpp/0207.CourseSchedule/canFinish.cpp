class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> > m;
        vector<int> pre_counts(numCourses, 0);
        for (auto v: prerequisites) {
            m[v[1]].push_back(v[0]);
            pre_counts[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (!pre_counts[i]) q.push(i);
        int count = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            count++;
            for (int n: m[cur]) {
                pre_counts[n]--;
                if (!pre_counts[n]) q.push(n);
            }
        }
        if (count == numCourses) return true;
        return false;
    }
};