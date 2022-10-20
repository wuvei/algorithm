class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 1, cnt = 0;
        unordered_map<int, int> m;
        for (int l = 0, r = 0; r < fruits.size(); ++r) {
            ++m[fruits[r]];
            if (m[fruits[r]] == 1) ++cnt;
            while (cnt > 2) {
                --m[fruits[l]];
                if (!m[fruits[l]]) --cnt;
                ++l;
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};