class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());
        for (auto &x : spells)
            x = potions.end() - upper_bound(potions.begin(), potions.end(), (success - 1) / x);
        return spells;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/solutions/1595712/by-endlesscheng-1kbp/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。