class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c: s) count[c]++;
        int ans = 0;
        bool hasOdd = false;
        for (auto &p: count) {
            if (p.second & 1) hasOdd = true;
            ans += ((p.second >> 1) << 1);
        }
        if (hasOdd) ans++;
        return ans;
    }
};