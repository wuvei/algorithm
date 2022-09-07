class Solution {
public:
    char repeatedCharacter(string s) {
        int cnt[26] = {};
        for (char c: s) {
            ++cnt[c - 'a'];
            if (cnt[c - 'a'] > 1)
                return c;
        }
        return 'a';
    }
};