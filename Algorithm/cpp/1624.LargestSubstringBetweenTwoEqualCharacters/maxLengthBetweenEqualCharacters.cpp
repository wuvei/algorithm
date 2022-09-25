class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]].push_back(i);
        }
        int ans = -1;
        for (auto &[k, v]: mp) {
            if (v.size() > 1) {
                ans = std::max(ans, v.back() - v[0] - 1);
            }
        }
        return ans;
    }
};