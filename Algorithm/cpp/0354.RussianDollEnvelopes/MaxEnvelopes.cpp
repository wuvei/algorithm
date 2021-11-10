class Solution {
public:
    // dp
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        // 首先执行排序，按照宽度排序，小的在前大的在后
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                // 对于宽度相等的信封，根据高度逆序，大的在前小的在后
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        // 预开空间,设初始值为1,即仅包含当前信封
        vector<int> dp(n, 1);

        int ans = 0;
        // 计算最长上升子序列
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(envelopes[j][1] < envelopes[i][1]){
                    // 如果h严格升序，尝试更新dp[i]
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // 尝试更新最大值ans
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

class Solution2 {
public:
    // 单增序列 + 二分查找
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        // 首先执行排序，按照宽度排序，小的在前大的在后
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                // 对于宽度相等的信封，根据高度逆序，大的在前小的在后
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        // 预开空间,初始值为排序后第一个信封的高度
        vector<int> dp(1, envelopes[0][1]);

        int ans = 0;
        // 计算最长上升子序列
        // 第0个元素已默认放入dp，因此从1开始遍历
        for(int i = 1; i < n; i++){
            // 搜索合适的更新位置，使用二分模板
            // 额外引入一个index来记录满足条件合法的值
            // 有的人的模板中，只有l和r两个变量，但是那个边界条件我总是记不住
            // 引入一个新的变量，个人感觉逻辑更明朗
            int l = 0, r = dp.size() - 1;
            int index = -1;
            while(l <= r){
                // mid这里用l加一半的形式，不容易溢出int
                int mid = l + (r - l) / 2;
                if(dp[mid] >= envelopes[i][1]){
                    // 我们要找的是dp数组中第一个大于等于当前h的位置
                    // 因此在这里更新index值
                    index = mid;
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            if(index == -1){
                dp.emplace_back(envelopes[i][1]);
            }
            else{
                dp[index] = envelopes[i][1];
            }
        }
        return dp.size();
    }
    // 二分查找用std::lower_bound替代
    int maxEnvelopes2(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            if (int num = envelopes[i][1]; num > f.back()) {
                f.push_back(num);
            }
            else {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return f.size();
    }
};