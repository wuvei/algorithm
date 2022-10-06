class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < s1.size(); ++i) {
            ++m1[s1[i]];
            ++m2[s2[i]];
        }
        return m1 == m2;
    }
};