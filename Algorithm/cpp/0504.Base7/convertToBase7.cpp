class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string add = "";
        if (num < 0) {
            num = -num;
            add = "-";
        }
        string ans = "";
        while (num) {
            ans += num % 7 + '0';
            num /= 7;
        }
        ans += add;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};