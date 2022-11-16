class Solution {
public:
    int vow[26] = {};
    Solution() {
        vow[0] = 1;
        vow[4] = 1;
        vow[8] = 1;
        vow[14] = 1;
        vow[20] = 1;
    }
    bool halvesAreAlike(string s) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0, j = s.size() >> 1; j < s.size(); ++i, ++j) {
            if (vow[tolower(s[i]) - 'a']) ++cnt1;
            if (vow[tolower(s[j]) - 'a']) ++cnt2;
        }
        return cnt1 == cnt2;
    }
};