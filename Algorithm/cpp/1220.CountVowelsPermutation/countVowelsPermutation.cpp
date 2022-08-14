// DP
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int> > dp(2, vector<int>(5, 1)), prev{{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}};
        constexpr int mod = static_cast<int>(1e9) + 7;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 5; ++j) {
                int temp = 0;
                for (int p: prev[j])
                    temp = (temp + dp[(i + 1) & 1][p]) % mod;
                dp[i & 1][j] = temp;
            }    
        }
        
        int ans = 0;
        for (int i = 0; i < 5; ++i)
            ans = (ans + dp[n & 1][i]) % mod;
        
        return ans;
        
    }
};

// fast matrix multiply
using LL = long long;
using Mat = vector<vector<LL> >;

class Solution {
private:
    static constexpr int mod = static_cast<int>(1e9) + 7;
public:     
    Mat multiply(const Mat & matrixA, const Mat & matrixB) {
        int m = matrixA.size();
        int n = matrixB[0].size();
        Mat res(m, vector<LL>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < matrixA[i].size(); ++k) {
                    res[i][j] = (res[i][j] + matrixA[i][k] * matrixB[k][j]) % mod;
                }
            }
        }
        return res;
    }
     
    Mat fastPow(const Mat & matrix, LL n) {
        int m = matrix.size();
        Mat res(m, vector<LL>(m, 0));
        Mat curr = matrix;

        for (int i = 0; i < m; ++i) {
            res[i][i] = 1;
        }
        for (int i = n; i != 0; i >>= 1) {
            if (i & 1) {
                res = multiply(curr, res);
            }
            curr = multiply(curr, curr);
        }
        return res;
    }

    int countVowelPermutation(int n) {
        Mat factor =
        {
            {0, 1, 0, 0, 0}, 
            {1, 0, 1, 0, 0}, 
            {1, 1, 0, 1, 1}, 
            {0, 0, 1, 0, 1}, 
            {1, 0, 0, 0, 0}
        };
        Mat res = fastPow(factor, n - 1);
        long long ans = 0;
        for (int i = 0; i < 5; ++i) {
            ans = (ans + accumulate(res[i].begin(), res[i].end(), 0LL)) % mod;
        }
        return  ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/count-vowels-permutation/solution/tong-ji-yuan-yin-zi-mu-xu-lie-de-shu-mu-jxo09/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。