class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> g(n);
        for (auto &v: roads) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        long long ans = 0;
        std::function<int(int, int)> dfs = [&](int root, int p) {
            int nums = 0;
            for (int next: g[root]) {
                if (p == next) continue;
                int t = dfs(next, root);
                ans += (t + seats - 1) / seats;
                nums += t;
            }
            return nums + 1;
        };
        dfs(0, 0);
        return ans;
    }
};