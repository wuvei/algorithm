class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        int lp = pattern.size();
        ans.reserve(queries.size());
        for (auto &s : queries) {
            int j = 0;
            bool flag = true;
            for (int i = 0; i < s.size() && flag; ++i) {
                if (j < lp && s[i] == pattern[j]) {
                    ++j;
                }
                else if (std::isupper(s[i])) 
                    flag = false;
            }
            ans.push_back(flag && j == lp);
        }
        return std::move(ans);
    }
};