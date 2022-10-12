class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (palindrome.size() == 1) {
            return "";
        }
        for (int i = 0, half = n >> 1; i < half; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};