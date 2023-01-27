class Solution {
public:
    string greatestLetter(string s) {
        int cnt[26] = {}, idx;
        char ans = 'A' - 1, upper;
        for (char c: s) {
            upper = std::toupper(c);
            idx = upper - 'A';
            if (std::islower(c)) cnt[idx] |= 1;
            else cnt[idx] |= 2;
            if (cnt[idx] == 3 && ans < upper) {
                ans = upper;
            }
        }
        return ans == 'A' - 1 ? "" : string(1, ans);
    }
};