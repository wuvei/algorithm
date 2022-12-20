class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int> > graph(n + 1);
        for (auto &v: edges) {
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }
        vector<int> odds;
        for (int i = 1; i <= n; ++i) {
            if (graph[i].size() & 1) {
                odds.push_back(i);
            }
        }
        if (odds.size() == 0) return true;
        if (odds.size() == 2) {
            int a = odds[0], b = odds[1];
            if (graph[a].find(b) == graph[a].end()) return true;
            for (int i = 1; i <= n; ++i) {
                if (i != a && i != b && graph[i].find(a) == graph[i].end() && graph[i].find(b) == graph[i].end()) return true;
            }
            return false;
        }
        if (odds.size() == 4) {
            bool temp[4][4];
            for (int i = 0; i < 4; ++i) {
                for (int j = i + 1; j < 4; ++j) {
                    temp[i][j] = graph[odds[i]].find(odds[j]) == graph[odds[i]].end();
                }
            }
            return (temp[0][1] && temp[2][3]) ||
            (temp[0][2] && temp[1][3]) ||
            (temp[0][3] && temp[1][2]);
        }
        return false;
    }
};