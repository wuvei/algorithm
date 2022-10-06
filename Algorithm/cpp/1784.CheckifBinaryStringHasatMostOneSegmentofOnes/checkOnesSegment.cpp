class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 1;
        while (s[i] == '1') {
            ++i;
        }
        while (s[i] == '0') {
            ++i;
        }
        return i == s.size();
    }
};