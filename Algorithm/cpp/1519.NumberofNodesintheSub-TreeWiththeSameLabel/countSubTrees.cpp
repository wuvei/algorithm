class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for (auto &v: edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<int> ans(n, 0);
        std::function<vector<int>(int, int)> dfs = [&](int node, int p) {
            vector<int> cnt(26, 0);
            for (int next: graph[node]) {
                if (next == p) continue;
                vector<int> temp = dfs(next, node);
                for (int i = 0; i < cnt.size(); ++i)
                    cnt[i] += temp[i];
            }
            ans[node] = ++cnt[labels[node] - 'a'];
            return std::move(cnt);
        };
        dfs(0, -1);
        return ans;
    }
};