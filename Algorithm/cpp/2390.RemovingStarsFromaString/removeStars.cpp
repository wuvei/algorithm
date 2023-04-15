class Solution {
public:
    string removeStars(string s) {
        int cnt = 0;
        string ans;
        ans.reserve(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '*') ++cnt;
            else if (cnt) --cnt;
            else ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return std::move(ans);
    }
};