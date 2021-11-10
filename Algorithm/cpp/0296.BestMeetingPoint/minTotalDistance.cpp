class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        return getMd(rows) + getMd(cols);
    }
    int getMd(vector<int> &v) {
        sort(v.begin(), v.end());
        int l = 0, r = v.size() - 1, ans = 0;
        while(l < r) {
            ans += v[r--] - v[l++];
        }
        return ans;
    }
};