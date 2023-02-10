class Solution {
public:
    long long distinctNames(vector<string> &ideas) {
        unordered_map<string, int> group;
        for (auto &s : ideas)
            group[s.substr(1)] |= 1 << (s[0] - 'a');
        long long ans = 0L;
        int cnt[26][26] = {};
        for (auto &[_, mask] : group)
            for (int i = 0; i < 26; i++)
                if ((mask >> i & 1) == 0) {
                    for (int j = 0; j < 26; j++)
                        if (mask >> j & 1) ++cnt[i][j];
                } else {
                    for (int j = 0; j < 26; j++)
                        if ((mask >> j & 1) == 0) ans += cnt[i][j];
                }
        return ans << 1;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/naming-a-company/solutions/1596320/by-endlesscheng-ruz8/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。