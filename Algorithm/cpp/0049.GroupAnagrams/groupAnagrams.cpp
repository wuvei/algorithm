class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(i);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            vector<string> temp;
            for (int e: it -> second)
                temp.push_back(strs[e]);
            result.push_back(std::move(temp));
        }
        return result;
    }
};