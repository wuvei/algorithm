class Solution {
public:
    int countTriplets(vector<int> &nums) {
        int u = 1;
        for (int x : nums)
            while (u <= x)
                u <<= 1;
        vector<int> cnt(u, 0);
        cnt[0] = nums.size(); // 直接统计空集
        for (int m : nums) {
            m ^= u - 1;
            for (int s = m; s > 0; s = (s - 1) & m) // 枚举 m 的非空子集
                ++cnt[s];
        }
        int ans = 0;
        for (int x : nums)
            for (int y : nums)
                ans += cnt[x & y];
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/solutions/2145654/you-ji-qiao-de-mei-ju-chang-shu-you-hua-daxit/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。