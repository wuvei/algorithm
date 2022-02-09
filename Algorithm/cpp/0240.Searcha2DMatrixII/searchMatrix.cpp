class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), i = m - 1, j = 0;
        while (j < n && i >= 0) {
            int temp = matrix[i][j];
            if (temp == target) return true;
            else if (temp > target) i--;
            else j++;
        }
        return false;
    }
};