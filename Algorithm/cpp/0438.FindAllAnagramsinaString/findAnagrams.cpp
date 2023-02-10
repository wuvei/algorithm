class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return vector<int>();
        int code[26]{}, cnt = 0;
        for (char c: p) {
            ++code[c - 'a'];
            if (code[c - 'a'] == 1)
                ++cnt;
        }
        vector<int> ans;
        int l = p.size();
        for (int i = 0; i < l; ++i) {
            int idx = s[i] - 'a';
            --code[idx];
            if (code[idx] == 0) --cnt;
        }
        if (cnt == 0) ans.push_back(0);
        for (int i = l; i < s.size(); ++i) {
            int idx1 = s[i - l] - 'a', idx2 = s[i] - 'a';
            ++code[idx1];
            if (code[idx1] == 1) ++cnt;
            --code[idx2];
            if (code[idx2] == 0) --cnt;
            if (!cnt) ans.push_back(i - l + 1);
        }
        return std::move(ans);
    }
};