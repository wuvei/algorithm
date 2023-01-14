class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for (auto &v: edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n, false);
        vis[0] = true;
        std::function<int(int)> dfs = [&](int vertex) {
            int time = 0;
            for (int e: graph[vertex]) {
                if (!vis[e]) {
                    vis[e] = true;
                    time += dfs(e);
                }
            }
            if (vertex > 0 && (time > 0 || hasApple[vertex])) {
                time += 2;
            }
            return time;
        };
        return dfs(0);
    }
};