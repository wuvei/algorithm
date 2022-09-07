class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        bool isRight = n > m;
        vector<int> prefix_sum((isRight ? n + 1 : m + 1), 0);
        int ans = INT_MIN;
        for(int i = 1; i <= (isRight ? m : n); ++i){
            fill(prefix_sum.begin(), prefix_sum.end(), 0);
            for(int j = i; j <= (isRight ? m : n); ++j){
                set<int> st;
                st.insert(0);
                int a = 0;
                for(int fixed = 1; fixed <= (isRight ? n : m); ++fixed){
                    prefix_sum[fixed] += isRight ? mat[j - 1][fixed - 1] : mat[fixed - 1][j - 1];
                    a += prefix_sum[fixed];
                    auto b = st.lower_bound(a - k);
                    if(b != st.end()){
                        int cur = a - *b;
                        ans = max(ans,cur);
                    }
                    st.insert(a);
                }
            }
        }
        return ans;
    }
};

// 作者：AC_OIer
// 链接：https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k/solution/gong-shui-san-xie-you-hua-mei-ju-de-ji-b-dh8s/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。