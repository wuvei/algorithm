class Solution {
public:
    void f(string &word, unordered_map<int, int> &m, unordered_set<char> &s) {
        int count[26] = {};
        for (char c: word) {
            ++count[c - 'a'];
            s.insert(c);
        }
        for (int i = 0; i < 26; ++i)
            ++m[count[i]];
    }
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<int, int> freq1, freq2;
        unordered_set<char> s1, s2;
        f(word1, freq1, s1);
        f(word2, freq2, s2);
        return s1 == s2 && freq1 == freq2;
    }
};