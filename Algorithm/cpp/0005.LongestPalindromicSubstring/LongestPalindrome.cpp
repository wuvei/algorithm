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


// Manacher Alg
class Solution {
public:
    string longestPalindrome(string s) {
        int n = 2 * s.size() + 3;
        vector<char> str(n, '#');
        str[0] = '!'; str[n - 1] = '$';
        for (int i = 2; i < n - 2; i += 2)
            str[i] = s[i / 2 - 1];
        vector<int> p(n, 0);
        int mid = 0, rt = 0, maxLen1 = 0, center = 0;
        for (int i = 1; i < n - 1; i++) {
            p[i] = i < rt ? min(p[2 * mid - i], rt - i) : 1;
            while (str[i + p[i]] == str[i - p[i]]) p[i]++;
            if (i + p[i] > rt) {
                rt = i + p[i];
                mid = i;
            }
            if (maxLen1 < p[i]) {
                maxLen1 = p[i];
                center = i;
            }
        }
        string ans;
        for (int i = center - maxLen1 + 1; i < center + maxLen1; i++)
            if (str[i] != '#') ans += str[i];
        return ans;
    }
};