class Solution {
public:
    char firstUniqChar(string s) {
        if (!s.compare("")) return ' ';
        int count[26] = {};
        for(char c: s) {
            count[int(c - 'a')]++;
        }
        for(char c: s) {
            if (count[int(c - 'a')] == 1) return c;
        }
        return ' ';
    }
};