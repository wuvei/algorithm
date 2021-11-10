class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<int>();
        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans(row * col);
        int k = 0, l = 0, r = col - 1, t = 0, b = row - 1;
        while(k < col * row){
            for(int i = l; i <= r; i++)
                ans[k++] = matrix[t][i];
            t++;
            for(int i = t; i <= b; i++)
                ans[k++] = matrix[i][r];
            r--;
            for(int i = r; i >= l && t <= b; i--)
                ans[k++] = matrix[b][i];
            b--;
            for(int i = b; i >= t && l <= r;i--)
                ans[k++] = matrix[i][l];
            l++;
        }
        return ans;
    }
};