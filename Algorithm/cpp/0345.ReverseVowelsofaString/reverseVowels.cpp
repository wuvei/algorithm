class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u'};
        while (l < r) {
            while (l < r && vowel.find(std::tolower(s[l])) == vowel.end()) ++l;
            while (l < r && vowel.find(std::tolower(s[r])) == vowel.end()) --r;
            if (l < r)
                swap(s[l], s[r]);
            ++l;
            --r;
        }
        return s;
    }
};