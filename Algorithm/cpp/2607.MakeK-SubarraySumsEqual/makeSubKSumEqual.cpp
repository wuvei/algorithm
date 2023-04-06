class Solution {
public:
    long long makeSubKSumEqual(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == k) return 0;
        k = gcd(k, n);
        vector<vector<int>> g(k);
        for (int i = 0; i < n; ++i)
            g[i % k].push_back(arr[i]);

        long long ans = 0;
        for (auto &b: g) {
            int mid = b.size() >> 1;
            std::nth_element(b.begin(), b.begin() + mid, b.end());
            for (int x: b)
                ans += abs(x - b[mid]);
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/make-k-subarray-sums-equal/solutions/2203591/zhuan-huan-zhong-wei-shu-tan-xin-pei-shu-4dut/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。