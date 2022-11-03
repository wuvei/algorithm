class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int cnt = 0;
        for (char c: s) {
            if (!isdigit(c)) {
                ++cnt;
            }
        }
        int total = 1 << cnt;
        vector<string> ans;
        for (int i = 0; i < total; ++i) {
            for (int j = 0, k = 0; j < s.size(); ++j) {
                if (isdigit(s[j])) continue;
                if (i & (1 << k)) s[j] = std::toupper(s[j]);
                else s[j] = std::tolower(s[j]);
                ++k;
            }
            ans.push_back(s);
        }
        return ans;
    }
};