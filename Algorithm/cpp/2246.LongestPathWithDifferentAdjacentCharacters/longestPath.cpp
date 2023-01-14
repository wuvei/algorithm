class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size(), ans = 0;
        vector<vector<int>> child(n);
        for (int i = 1; i < n; ++i) {
            child[parent[i]].push_back(i);
        }
        std::function<int(int)> dfs = [&](int node) {
            int maxLen = 0;
            for (int c: child[node]) {
                int len = dfs(c) + 1;
                if (s[node] != s[c]) {
                    ans = max(ans, maxLen + len);
                    maxLen = max(maxLen, len);
                }
            }
            return maxLen;
        };
        dfs(0);
        return ans + 1;
    }
};