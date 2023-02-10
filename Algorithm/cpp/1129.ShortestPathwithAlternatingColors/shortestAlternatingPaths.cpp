class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        auto g = vector<vector<vector<int>>>(n, vector<vector<int>>(2));
        for (auto &v: redEdges)
            g[v[0]][0].push_back(v[1]);
        for (auto &v: blueEdges) {
            g[v[0]][1].push_back(v[1]);
        }
        queue<pair<int, int> > q;
        for (int i = 0; i < 2; ++i)
            for (int e: g[0][i]) q.push({e, i});
        vector<int> ans(n, -1), vis(n, 0);
        ans[0] = 0;
        int step = 1;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto [node, prev] = q.front();
                q.pop();
                if (ans[node] == -1)
                    ans[node] = step;
                for (int next: g[node][1 - prev]) {
                    if ((vis[next] & (prev == 1 ? 1 : 2)) == 0) {
                        vis[next] |= (prev == 1 ? 1 : 2);
                        q.push({next, 1 - prev});
                    }
                }
            }
            ++step;
        }
        return std::move(ans);
    }
};