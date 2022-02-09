class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        vector<int> row(c);
        int x = 0, y = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[y++] = nums[i][j];
                if (y == c) {
                    ans[x++] = row;
                    y = 0;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x) {
            ans[x / c][x % c] = nums[x / n][x % n];
        }
        return ans;
    }
};