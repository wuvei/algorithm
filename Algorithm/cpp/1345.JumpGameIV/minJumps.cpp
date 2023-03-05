class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return n - 1;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i)
            m[arr[i]].push_back(i);
        vector<bool> vis(n, false);
        unordered_set<int> s;
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int ans = 0;
        auto f = [&](int pos) {
            if (!vis[pos]) {
                q.push(pos);
                vis[pos] = true;
            }
        };
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int e = q.front();
                q.pop();
                if (e == n - 2) return ans + 1;
                if (!s.count(arr[e])) {
                    for (int i = m[arr[e]].size() - 1; i >= 0; --i) {
                        int next = m[arr[e]][i];
                        if (next == n - 1) return ans + 1;
                        f(next);
                    }
                    s.insert(arr[e]);
                }
                if (e) f(e - 1);
                if (e < n - 1) f(e + 1); 
            }
            ++ans;
        }
        return -1;
    }
};