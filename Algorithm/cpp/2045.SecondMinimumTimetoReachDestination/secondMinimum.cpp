class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int> > mp;
        for (auto v: edges) {
            if (mp.find(v[0]) != mp.end()) mp[v[0]].push_back(v[1]);
            else mp[v[0]] = vector<int>({v[1]});
            if (mp.find(v[1]) != mp.end()) mp[v[1]].push_back(v[0]);
            else mp[v[1]] = vector<int>({v[0]});
        }
        int count = 0, cur_time = 0;
        vector<int> visited(n+1,0);
        vector<int> dist(n+1,-1);
        queue<pair<int, int> > q;
        q.push({1, 0});
        while (!q.empty()) {
            auto [vertex, t] = q.front();
            q.pop();
            int tt;
            int round = t/change;
            if (round%2==0)
                tt = t+time;
            else
                tt = (round+1)*change + time;
            
            for (int e: mp[vertex]) {
                if (visited[e]<2 && dist[e] < tt){
                    dist[e] = tt;
                    visited[e]+=1;
                    q.push({e, tt});
                    if (visited[e]==2 && e==n)
                        return tt;
                }
            }
        }
        return -1;
    }
};