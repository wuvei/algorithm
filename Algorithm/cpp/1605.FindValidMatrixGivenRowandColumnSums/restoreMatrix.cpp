class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0, j = 0; i < m && j < n; ) {
            int rs = rowSum[i], cs = colSum[j];
            if (rs < cs) {
                ans[i++][j] = rs;
                colSum[j] -= rs;
            } else {
                ans[i][j++] = cs;
                rowSum[i] -= cs;
            }
        }
        return std::move(ans);
    }
};