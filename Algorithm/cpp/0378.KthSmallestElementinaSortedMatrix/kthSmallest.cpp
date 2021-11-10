class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r) {
            int mid = l + (r - l) / 2, n = smallerOrEqual(matrix, mid);
            if (n >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    int smallerOrEqual(vector<vector<int>>& matrix, int x) {
        int i = matrix.size() - 1, j = 0, sum = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] <= x) {
                sum += i + 1;
                j++;
            }
            else i--;
        }
        return sum;
    }
};