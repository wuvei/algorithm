class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for (auto &v : paths) {
            int p1 = v[0] - 1, p2 = v[1] - 1;
            g[p1].push_back(p2);
            g[p2].push_back(p1);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int mask = 1;
            for (int e : g[i])
                mask |= 1 << ans[e];
            ans[i] = __builtin_ctz(~mask);
        }
        return std::move(ans);
    }
};