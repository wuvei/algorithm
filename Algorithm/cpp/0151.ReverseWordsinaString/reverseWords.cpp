class Solution {
public:
    void rev(string &s, int l, int r) {
        while (l < r) {
            char c = s[l];
            s[l++] = s[r];
            s[r--] = c;
        }
    }
    string reverseWords(string s) {
        int start = 0, l = 0, r = 0, n = s.size();
        while(r < n && s[r] == ' ') r++;
        while (r < n) {
            while(r < n && s[r] != ' ') s[l++] = s[r++];
            rev(s, start, l - 1);
            while(r < n && s[r] == ' ') r++;
            if (r < n) s[l++] = ' ';
            start = l;
        }
        rev(s, 0, l - 1);
        return s.substr(0, l);
    }
};