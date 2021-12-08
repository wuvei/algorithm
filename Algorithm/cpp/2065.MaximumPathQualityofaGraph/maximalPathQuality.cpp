class Solution {
public:
    inline void dijkstra(int s) //最短路模板
    {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pru; // Min Heap
        dis.resize(n, INT_MAX);
        vector<bool> vis(n, false);
        dis[s] = 0;
        pru.push({0, s});
        while(!pru.empty())
        {
            int u = pru.top().second;
            pru.pop();
            if (!vis[u]) {
                vis[u] = true;
                for (auto v: next_nodes[u]) {
                    int to_node = v.first;
                    if (dis[to_node] > dis[u] + v.second) {
                        dis[to_node] = dis[u] + v.second;
                        pru.push({dis[to_node], to_node});
                    }
                }
            }
        }
        return;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        n = values.size();
        // adjacency list
        next_nodes.resize(n, vector<pair<int, int> >());
        for (auto v: edges) {
            next_nodes[v[0]].push_back({v[1], v[2]});
            next_nodes[v[1]].push_back({v[0], v[2]});
        }
        // Dijkstra: min time from 0 to each node
        dijkstra(0);
        // DFS
        visited.resize(n, 0);
        quality = 0;
        function<void(int, int, int)> dfs = [&](int s, int curVal, int leftTime){
            if (s == 0) quality = std::max(quality, curVal);
            for (auto v: next_nodes[s]) {
                int to_node = v.first;
                if (dis[to_node] + v.second <= leftTime) {
                    visited[to_node]++;
                    dfs(to_node, curVal + (visited[to_node] == 1? values[to_node]: 0), leftTime - v.second);
                    visited[to_node]--;
                }
            }
        };
        visited[0] = 1;
        dfs(0, values[0], maxTime);
        return quality;
    }
private:
    int n, quality;
    vector<vector<pair<int, int> > > next_nodes;
    vector<int> dis, visited;
};