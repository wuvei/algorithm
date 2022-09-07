class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> diag;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diag[i - j].push_back(mat[i][j]);
            }
        }
        for (auto &it: diag)
            sort(it.second.begin(), it.second.end());
        auto ans = mat;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                ans[i][j] = diag[i - j].back();
                diag[i - j].pop_back();
            }
        }
        return ans;
    }
};