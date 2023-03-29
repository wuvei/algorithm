class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> g(n);
        vector<int> degree(n, 0);
        for (auto &v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
            ++degree[v[0]];
            ++degree[v[1]];
        }
        // trim leaves without coins;
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (coins[i] == 0 && degree[i] == 1)
                q.push(i);

        vector<bool> del(n, false);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            del[x] = true;
            for (int e : g[x]) {
                if (--degree[e] == 1 && coins[e] == 0)
                    q.push(e);
            }
        }

        // get all leaves with coin
        for (int i = 0; i < n; ++i)
            if (degree[i] == 1 && coins[i] == 1)
                q.push(i);
        if (q.size() <= 1) return 0;

        // do 2 rounds of trim
        for (int iter = 0; iter < 2; ++iter) {
            int len = q.size();
            while (len--) {
                int x = q.front();
                q.pop();
                del[x] = true;
                for (int e : g[x])
                    if (--degree[e] == 1)
                        q.push(e);
            }
        }
        int ans = 0;
        for (auto &v : edges) {
            if (!del[v[0]] && !del[v[1]])
                ans += 2;
        }
        return ans;
    }
};