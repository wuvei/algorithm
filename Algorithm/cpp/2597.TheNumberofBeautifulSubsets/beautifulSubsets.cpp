class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        vector<map<int, int>> groups(k);
        for (int x : nums)
            ++groups[x % k][x];
        int ans = 1;
        for (auto &g: groups) {
            if (!g.size()) continue;
            int m = g.size();
            vector<int> f(m + 1);
            auto it = g.begin();
            f[0] = 1;
            f[1] = 1 << it++->second;
            for (int i = 2; it != g.end(); ++it, ++i)
                if (it->first - prev(it)->first == k)
                    f[i] = f[i - 1] + f[i - 2] * ((1 << it->second) - 1);
                else
                    f[i] = f[i - 1] << it->second;
            ans *= f[m];
        }
        return ans - 1; // -1 去掉空集
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/the-number-of-beautiful-subsets/solutions/2177818/tao-lu-zi-ji-xing-hui-su-pythonjavacgo-b-fcgs/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。