class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(), [](auto &a, auto &b) {
            return a[0] > b[0] || a[0] == b[0] && a[1] < b[1];
        });
        int ans = 0, max_def = 0;
        for (auto &p : properties)
            if (p[1] < max_def) ++ans;
            else max_def = p[1];
        return ans;
    }
};

// 作者：endlesscheng
// 链接：https://leetcode.cn/problems/the-number-of-weak-characters-in-the-game/solution/jian-ji-xie-fa-pai-xu-yi-ci-bian-li-by-e-unnb/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。