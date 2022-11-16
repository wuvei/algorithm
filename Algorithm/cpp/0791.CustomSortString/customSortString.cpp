class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26] = {};
        for (char c : s) 
            ++cnt[c - 'a'];
        string ans;
        ans.reserve(s.size());
        for (char c : order) {
            ans += string(cnt[c - 'a'], c);
            cnt[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; ++i) 
            if (cnt[i] > 0)
                ans += string(cnt[i], i + 'a');
        return ans;
    }
};