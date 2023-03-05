class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        ans.reserve(names.size());
        unordered_map<string, int> m;
        for (auto &s : names) {
            if (m.count(s)) {
                string new_name;
                do {
                    new_name = s + "(" + std::to_string(m[s]) + ")";
                    ++m[s];
                } while (m.count(new_name));
                m[new_name] = 1;
                ans.push_back(new_name);
            } else {
                m[s] = 1;
                ans.push_back(s);
            }
        }
        return std::move(ans);
    }
};