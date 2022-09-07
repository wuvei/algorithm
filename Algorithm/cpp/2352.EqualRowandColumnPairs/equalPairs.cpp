class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rows;
        int n = grid.size();
        for (auto &v: grid) {
            string temp = "";
            for (int e: v)
                temp += to_string(e) + "#";
            ++rows[temp];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            string temp = "";
            for (int j = 0; j < n; ++j) {
                temp += to_string(grid[j][i]) + "#";
            }
            ans += rows[temp];
        }
        return ans;
    }
};