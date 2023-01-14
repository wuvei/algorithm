class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums) {
        int ans = 0, mx = *max_element(nums.begin(), nums.end());
        vector<bool> has(mx + 1, false);
        for (int x : nums)
            if (!has[x]) {
                has[x] = true;
                ++ans;
            }
        for (int i = 1; i <= mx / 3; ++i) {
            if (has[i]) continue;
            int g = 0;
            for (int j = i << 1; j <= mx && g != i; j += i) {
                if (has[j])
                    g = gcd(g, j);
            }
            if (g == i) ++ans;
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/number-of-different-subsequences-gcds/solutions/2061079/ji-bai-100mei-ju-gcdxun-huan-you-hua-pyt-get7/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。