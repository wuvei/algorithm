class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m1[26] = {}, m2[26] = {};
        for (char c: ransomNote)
            ++m1[c - 'a'];
        for (char c: magazine)
            ++m2[c - 'a'];
        for (int i = 0; i < 26; ++i) {
            if (m1[i] > m2[i])
                return false;
        }
        return true;
    }
};