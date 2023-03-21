class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        vector<int> cnt(n, 0);
        for (auto &v: roads) {
            g[v[0]][v[1]] = g[v[1]][v[0]] = 1;
            ++cnt[v[0]];
            ++cnt[v[1]];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = std::max(ans, cnt[i] + cnt[j] - g[i][j]);
            }
        }
        return ans;
    }
};