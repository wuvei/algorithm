class Solution {
public:
    string Palindrome(string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        string longgest = "";
        for (int i = 0; i < s.size(); i++) {
            string s1 = Palindrome(s, i, i);
            string s2 = Palindrome(s, i, i + 1);
            longgest = std::max({longgest, s1, s2}, [](string s1, string s2) -> bool { return s1.size() < s2.size();});
        }
        return longgest;
    }
};