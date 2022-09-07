class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for (int i = 0; i < mat.size(); ++i) {
            int count = 0, col = 0, row = 0;
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j]) {
                    ++count;
                    row = i;
                    col = j;
                }
                if (count > 1) break;
            }
            if (count == 1) {
                int k = 0;
                for (; k < mat.size(); ++k) {
                    if (mat[k][col] && k != row)
                        break;
                }
                if (k == mat.size())
                    ++ans;
            }
        }
        return ans;
    }
};