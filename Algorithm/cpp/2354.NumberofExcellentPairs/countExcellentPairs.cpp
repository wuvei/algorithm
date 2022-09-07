class Solution {
public:
    int get_cnt(int n) {
        int ans = 0;
        while (n) {
            n = n & (n - 1);
            ++ans;
        }
        return ans;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        map<int, unordered_set<int> > m;
        for (int e: nums)
            m[get_cnt(e)].insert(e);
        vector<int> cnt, prefix_sum{0};
        for (auto &it: m) {
            cnt.push_back(it.first);
            prefix_sum.push_back(it.second.size() + prefix_sum.back());
        }
        
        long long ans = 0LL;
        int i = 0;
        for (; i < cnt.size() && (cnt[i] << 1) < k; ++i) {
            auto it = lower_bound(cnt.begin() + 1, cnt.end(), k - cnt[i]);
            if (it == cnt.end())
                continue;

            int j = it - cnt.begin();
            ans += (1LL * m[cnt[i]].size() * (prefix_sum.back() - prefix_sum[j])) << 1;
        }
        if (i < cnt.size()) {
            int temp = prefix_sum.back() - prefix_sum[i];
            ans += 1LL * temp * temp;
        }
        return ans;
    }
};


class Solution {
    static constexpr int U = 30;
public:
    long long countExcellentPairs(vector<int> &nums, int k) {
        int cnt[U] = {};
        for (int x : unordered_set<int>(nums.begin(), nums.end())) // 去重
            ++cnt[__builtin_popcount(x)];
        long ans = 0L;
        int s = 0;
        for (int i = k; i < U; ++i)
            s += cnt[i];
        for (int cx = 0; cx < U; ++cx) {
            ans += (long) cnt[cx] * s;
            int cy = k - 1 - cx;
            if (0 <= cy && cy < U) s += cnt[cy];
        }
        return ans;
    }
};

// 作者：endlesscheng
// 链接：https://leetcode.cn/problems/number-of-excellent-pairs/solution/deng-jie-zhuan-huan-pythonjavacgo-by-end-2qzs/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。