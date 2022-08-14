class Solution {
public:
    int m[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string s[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num) {
        string ans;
        for (int i = 0; i < 13; ++i) {
            int len = num / m[i];
            if (len > 0) {
                while (len--)
                    ans += s[i];
                num = num % m[i];
            }
        }
        return ans;
    }
};