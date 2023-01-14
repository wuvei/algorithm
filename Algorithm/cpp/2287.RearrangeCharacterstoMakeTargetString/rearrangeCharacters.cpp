class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cnt[26]{}, cnts[26]{};
        for (char c: target) ++cnt[c - 'a'];
        for (char c: s) ++cnts[c - 'a'];
        int ans = s.size();
        for (int i = 0; i < 26; ++i) {
            if (cnt[i])
                ans = std::min(ans, cnts[i] / cnt[i]);
        }
        return ans;
    }
};