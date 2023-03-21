class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pre_sum = 0, ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == k) {
                pre_sum += n;
            } else if (nums[i] < k) {
                --pre_sum;
            } else {
                ++pre_sum;
            }
            ans += mp[pre_sum - n];
            ans += mp[pre_sum - n - 1];
            ++mp[pre_sum];
        }
        return ans;
    }
};

// 作者：daydayUppp🎈
// 链接：https://leetcode.cn/problems/count-subarrays-with-median-k/solutions/2171675/daydayuppp-zhuan-hua-wen-ti-ha-xi-biao-q-etua/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。