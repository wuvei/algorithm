class Solution {
public:
    string makeGood(string s) {
        int i = 0, j;
        for (j = 1; j < s.size(); ++j) {
            if (i == -1 || abs(s[i] - s[j]) != 32) {
                s[++i] = s[j];
            } else {
                --i;
            }
        }
        return s.substr(0, i + 1);
    }
};