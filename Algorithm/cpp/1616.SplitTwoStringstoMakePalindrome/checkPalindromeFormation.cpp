class Solution {
public:
    bool ifPalindrome(string &a, int l, int r) {
        for (; l < r; ++l, --r) {
            if (a[l] != a[r]) return false;
        }
        return true;
    }
    bool check(string &a, string &b) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            if (a[l] != b[r]) break;
            ++l;
            --r;
        }
        return ifPalindrome(a, l, r) || ifPalindrome(b, l, r);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};