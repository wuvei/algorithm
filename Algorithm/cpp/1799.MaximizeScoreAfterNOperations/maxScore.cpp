class Solution {
public:
    int gcd[15][15];
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        int all = 1 << n;
        vector<int> dp(all);
        for(int i = 0; i < all; ++i){
            int cnt = __builtin_popcount(i);
            if(cnt & 1) continue;
            cnt >>= 1;
            for(int j = 0; j < n; ++j){
                for(int k = j + 1; k < n; ++k){
                    if((i >> j) & 1 and (i >> k) & 1){
                        dp[i] = max(dp[i],dp[i - (1 << j) - (1 << k)] + cnt * gcd[j][k]);
                    }
                }
            }
        }
        return dp[all - 1];
    }
};


// 作者：🍭可乐可乐吗QAQ
// 链接：https://leetcode.cn/problems/maximize-score-after-n-operations/solutions/722953/c-yu-chu-li-gcd-ji-yi-hua-sou-suo-zhuang-ch2m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。