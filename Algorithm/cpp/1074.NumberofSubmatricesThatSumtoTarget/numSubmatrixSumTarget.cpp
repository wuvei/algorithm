class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int> > prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j)
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = i; j <= m; ++j) {
                unordered_map<int, int> cnt;
                cnt[0] = 1;
                for (int k = 1; k <= n; ++k) {
                    int temp = prefix[j][k] - prefix[i - 1][k];
                    if (cnt.find(temp - target) != cnt.end())
                        ans += cnt[temp - target];
                    ++cnt[temp];
                }
            }
        }
        return ans;
    }
};

// https://leetcode.cn/problems/number-of-submatrices-that-sum-to-target/solution/gong-shui-san-xie-you-hua-mei-ju-de-ji-b-uttw/