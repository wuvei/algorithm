class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> deg(n, 0);
        for (auto &v : edges) {
            if (v[0] == v[1]) return -1;
            g[v[0]].push_back(v[1]);
            ++deg[v[1]];
        }
        int cnt = 0, ans = 0;
        vector<vector<int>> dp(n, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ++cnt;
            ++dp[v][colors[v] - 'a'];
            ans = std::max(ans, dp[v][colors[v] - 'a']);
            for (auto w : g[v]) {
                for (int i = 0; i < dp[v].size(); ++i)
                    dp[w][i] = std::max(dp[w][i], dp[v][i]);
                if (--deg[w] == 0)
                    q.push(w);
            }
        }
        if (cnt < n) return -1;
        return ans;
    }
};
