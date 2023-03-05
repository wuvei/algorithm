class Solution {
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < basket1.size(); ++i) {
            ++cnt[basket1[i]];
            --cnt[basket2[i]];
        }

        int mn = INT_MAX;
        vector<int> a;
        for (auto [x, c] : cnt) {
            if (c % 2) return -1;
            mn = min(mn, x);
            for (c = abs(c) / 2; c > 0; --c)
                a.push_back(x);
        }

        long ans = 0;
        nth_element(a.begin(), a.begin() + a.size() / 2, a.end()); // 快速选择
        for (int i = 0; i < a.size() / 2; ++i)
            ans += min(a[i], mn * 2);
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/rearranging-fruits/solutions/2093878/tan-xin-gou-zao-by-endlesscheng-c2ui/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。