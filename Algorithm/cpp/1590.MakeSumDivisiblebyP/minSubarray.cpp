class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {
        int x = std::accumulate(nums.begin(), nums.end(), 0LL) % p;
        if (x == 0) return 0;

        int n = nums.size(), ans = n, s = 0;
         // 由于下面 i 是从 0 开始的，前缀和下标就要从 -1 开始了
        unordered_map<int, int> last{{s, -1}};
        for (int i = 0; i < n; ++i) {
            s = (s + nums[i]) % p;
            last[s] = i;
            auto it = last.find((s - x + p) % p);
            if (it != last.end())
                ans = min(ans, i - it->second);
        }
        return ans < n ? ans : -1;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/make-sum-divisible-by-p/solutions/2158435/tao-lu-qian-zhui-he-ha-xi-biao-pythonjav-rzl0/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。