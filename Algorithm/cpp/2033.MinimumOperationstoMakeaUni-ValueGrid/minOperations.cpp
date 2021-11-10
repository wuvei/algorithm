class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a(grid.size() * grid[0].size());
        int remainder = grid[0][0] % x, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != remainder) return -1;
                a[i * n + j] = grid[i][j];
            }
        }
        sort(a.begin(), a.end());
        int l = 0, r = a.size() - 1, ans = 0;
        while (l < r) {
            ans += (a[r--] - a[l++]) / x;
        }
        return ans;
    }
};