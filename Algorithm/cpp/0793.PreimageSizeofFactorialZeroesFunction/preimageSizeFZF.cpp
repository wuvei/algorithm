class Solution {
public:
    long long f(long long x) {
        long long ans = 0ll;
        for(x /= 5;x != 0;x /= 5)
            ans += x;
        return ans;
    }

    int preimageSizeFZF(int k) {
        long long l = 4ll * k, r = 5ll * k;
        while (l < r) {
            const long long m = (l + r) / 2;
            if (f(m) < k)
                l = m + 1;
            else r = m;
        }
        return f(l) == k ? 5 : 0;
    }
};

// 作者：vclip
// 链接：https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/solution/by-vclip-9quy/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。