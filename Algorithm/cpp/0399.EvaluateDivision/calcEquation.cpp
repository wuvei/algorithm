class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> ans;
        for (auto &q: queries) {
            if (q[0] == q[1] && graph.find(q[0]) != graph.end()) {
                ans.push_back(1);
                continue;
            }
            queue<pair<string, double> > que;
            unordered_set<string> visited;
            que.push({q[0], 1.0});
            bool flag = false;
            while (!que.empty() && !flag) {
                auto [var, cur] = que.front();
                que.pop();
                visited.emplace(var);
                for (auto &p: graph[var]) {
                    if (p.first == q[1]) {
                        flag = true;
                        ans.push_back(cur * p.second);
                        break;
                    }
                    if (visited.find(p.first) == visited.end())
                        que.push({p.first, cur * p.second}); 
                }
            }
            if (!flag) ans.push_back(-1.0);
        }
        return ans;
    }
private:
    unordered_map<string, vector<pair<string, double> > > graph;

};