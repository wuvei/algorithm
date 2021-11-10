class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 1 || n == 1) {
            for (auto v: matrix) {
                for (auto c: v) {
                    if (c == '1') return 1;
                }
            }
            return 0;
        }
        vector <vector <int>> dp(2, vector<int>(n, 0));
        int Max = 0, idx = 1;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                Max = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[idx][j] = std::min({ dp[1- idx][j], j? dp[idx][j - 1]: 0, j? dp[1 - idx][j - 1]: 0 }) + 1;
                    Max = std::max(dp[idx][j], Max);
                }
                else dp[idx][j] = 0;
                
            }
            idx = 1 - idx;
        }
        
        return Max * Max;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 1 || n == 1) {
            for (auto v: matrix) {
                for (auto c: v) {
                    if (c == '1') return 1;
                }
            }
            return 0;
        }
        vector <int> dp(n + 1, 0);
        int Max = 0, northwest = 0;
        for (auto v: matrix) {
            northwest = 0;
            for (int col = 0; col < n; col++) {
                int nextNorthwest = dp[col + 1];
                if (v[col] == '1') {
                    dp[col + 1] = std::min({ dp[col], dp[col + 1], northwest }) + 1;
                    Max = std::max(dp[col + 1], Max);
                }
                else dp[col + 1] = 0;
                northwest = nextNorthwest;
            }
        }
        
        return Max * Max;
    }

};