class Solution {
public:
    vector<int> cur;
    vector<bool> visit;
    vector<vector<int>> ans;
    int n;
    void backtracking(int p, vector<vector<int>>& graph) {
        if (p == n - 1) {
            ans.emplace_back(cur);
            return;
        }
        for (int e: graph[p]) {
            if (visit[e]) continue;
            visit[e] = true;
            cur.push_back(e);
            backtracking(e, graph);
            cur.pop_back();
            visit[e] = false;
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        cur = {0};
        n = graph.size();
        cur.reserve(n);
        visit.resize(n, false);
        visit[0] = true;
        backtracking(0, graph);
        return ans;
    }
};