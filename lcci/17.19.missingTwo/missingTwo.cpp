// sum
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2, cur = n * (1 + n) / 2;
        cur -= std::accumulate(nums.begin(), nums.end(), 0);
        int sum = cur, t = cur / 2;
        cur = t * (1 + t) / 2;
        for (int x : nums) {
            if (x <= t) {
                cur -= x;
            }
        }
        return {cur, sum - cur};
    }
};

// xor
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2, eor = 0;
        for (int v : nums) {
            eor ^= v;
        }
        for (int i = 1; i <= n; ++i) {
            eor ^= i;
        }
        int diff = eor & -eor, a = 0;
        for (int v : nums) {
            if (v & diff) a ^= v;
        }
        for (int i = 1; i <= n; ++i) {
            if (i & diff) a ^= i;
        }
        return {a, eor ^ a};
    }
};

// 作者：lcbin
// 链接：https://leetcode.cn/problems/missing-two-lcci/solution/by-lcbin-jpie/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。