class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        unordered_map<int, unordered_set<int> > m;
        for (auto &v: logs) {
            m[v[0]].insert(v[1]);
        }
        for (auto &it: m) {
            ++ans[it.second.size() - 1];
        }
        return ans;
    }
};