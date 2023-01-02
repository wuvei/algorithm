class Solution {
public:
    int minimumLength(string s) {
        int l0 = 0, l = 0, r0 = s.length() - 1, r = r0;
        while (l < r) {
            while (l < r - 1 && s[l] == s[l + 1]) ++l;
            while (l < r - 1 && s[r] == s[r - 1]) --r;
            if (s[l] != s[r]) break;
            l0 = l = l + 1;
            r0 = r = r - 1;
        }
        return l0 <= r0 ? r0 - l0 + 1 : 0;
    }
};