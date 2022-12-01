class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> fail;
        for (auto &v: matches) {
            ++fail[v[1]];
            fail[v[0]];
        }
        vector<vector<int>> ans(2);
        for (auto &it: fail) {
            if (it.second == 1)
                ans[1].push_back(it.first);
            else if (it.second == 0)
                ans[0].push_back(it.first);
        }
        return ans;
    }
};