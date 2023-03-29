class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                ++indegree[edges[i]];
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                q.push(i);
        vector<bool> vis(n, false);
        while (!q.empty()) {
            int node = q.front();
            vis[node] = true;
            node = edges[node];
            q.pop();
            if (node == -1) continue;
            --indegree[node];
            if (indegree[node] == 0) q.push(node);
        }

        int ans = -1;
        std::function<int(int)> dfs = [&](int x) {
            vis[x] = true;
            if (vis[edges[x]]) return 1;
            else return dfs(edges[x]) + 1;
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) ans = std::max(ans, dfs(i));
        }
        return ans;
    }
};