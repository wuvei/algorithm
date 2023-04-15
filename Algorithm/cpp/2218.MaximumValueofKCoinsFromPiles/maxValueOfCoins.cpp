class Solution {
public:
    /* dp[i][j]: get j from the first i piles */
    /* dp[i][j] = max(dp[i][j], dp[i-1][j-w] + pile[w]  */
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1);
        int sumN = 0;
        for (auto &pile : piles) {
            int n = pile.size();
            for (int i = 1; i < n; i++)
                pile[i] += pile[i - 1];

            sumN = min(sumN + n, k);
            for (int j = sumN; j >= 1; --j) {
                for (int w = 1; w <= std::min(n, j); ++w) {
                    dp[j] = std::max(dp[j], dp[j - w] + pile[w - 1]);
                }
            }
        }
        return dp[k];
    }
};

// 作者：linge32
// 链接：https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/solutions/1373560/c-by-liu-xiang-3-hcmj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。