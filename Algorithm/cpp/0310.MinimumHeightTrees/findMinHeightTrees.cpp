class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        if (n == 1) return {0};
        vector<vector<int> > m(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto v: edges) {
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(v[0]);
            degree[v[0]]++;
            degree[v[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (m[i].size() == 1)
                q.push(i);
        }
        while(n > 2) {
            n -= q.size();
            for (int i = q.size(); i > 0; i--) {
                int cur = q.front();
                q.pop();
                for (int v: m[cur]) {
                    degree[v]--;
                    if (degree[v] == 1)
                        q.push(v);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};