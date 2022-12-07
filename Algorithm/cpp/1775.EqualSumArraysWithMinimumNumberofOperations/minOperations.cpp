class Solution {
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        if (6 * nums1.size() < nums2.size() || 6 * nums2.size() < nums1.size())
            return -1;
        int diff = accumulate(nums1.begin(), nums1.end(), 0) - accumulate(nums2.begin(), nums2.end(), 0);
        if (diff < 0) {
            diff = -diff;
            swap(nums1, nums2);
        }
        int cnt[6] = {};
        for (int x: nums1) ++cnt[x - 1];
        for (int x: nums2) ++cnt[6 - x];
        for (int i = 5, ans = 0;; --i) {
            if (i * cnt[i] >= diff)
                return ans + (diff + i - 1) / i;
            ans += cnt[i];
            diff -= i * cnt[i];
        }
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/solutions/2009786/mei-xiang-ming-bai-yi-ge-dong-hua-miao-d-ocuu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。