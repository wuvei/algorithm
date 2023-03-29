class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for (auto &v : connections) {
            g[v[0]].push_back(-v[1]);
            g[v[1]].push_back(v[0]);
        }
        int ans = 0;
        vector<bool> vis(n, false);
        vis[0] = true;
        std::function<void(int)> dfs = [&](int c) {
            for (int next: g[c]) {
                if (vis[std::abs(next)]) continue;
                if (next < 0) {
                    ++ans;
                    next = -next;
                }
                vis[next] = true;
                dfs(next);
            }
        };
        dfs(0);
        return ans;
    }
};