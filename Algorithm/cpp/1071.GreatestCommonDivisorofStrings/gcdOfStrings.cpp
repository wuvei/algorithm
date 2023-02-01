class Solution {
public:
    bool check(string &s, int len) {
        if (len == s.length()) return true;
        bool flag = true;
        for (int i = len; i < s.length() && flag; i += len) {
            for (int j = 0; j < len; ++j) {
                if (s[j] != s[j + i]) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length())
            std::swap(str1, str2);
        int l1 = str1.length(), l2 = str2.length(), ans = -1;
        for (int len = 1; len <= l2; ++len) {
            if (l2 % len != 0 || l1 % len != 0 || str1.substr(0, len) != str2.substr(0, len))
                continue;
            if (check(str2, len) && check(str1, len))
                ans = len;
        }
        return ans == -1 ? "" : str2.substr(0, ans);
    }
};