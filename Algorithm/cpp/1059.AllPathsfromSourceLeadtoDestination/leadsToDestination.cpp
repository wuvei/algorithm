bool acyclic(const vector<vector<int>>& graph, int u, int dest,
               vector<int>& state) {
    if (graph[u].empty())
        return u == dest;
    if (state[u] == 1)
        return false;
    if (state[u] == 2)
        return true;

    state[u] = 1;
    for (const int v : graph[u])
        if (!acyclic(graph, v, dest, state))
            return false;
    state[u] = 2;

    return true;
}
bool leadsToDestination(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    vector<int> state(n, 0);

    for (const auto& e : edges)
      graph[e[0]].push_back(e[1]);

    return acyclic(graph, src, dest, state);
}
