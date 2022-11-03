class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0, idx = 2;
        if (ruleKey == "type") idx = 0;
        else if (ruleKey == "color") idx = 1;
        for (auto &v: items) {
            if (v[idx] == ruleValue)
                ++ans;
        }
        return ans;
    }
};