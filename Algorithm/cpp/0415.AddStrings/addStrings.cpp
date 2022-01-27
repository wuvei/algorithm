class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "0") return num2;
        else if (num2 == "0") return num1;
        int n1 = num1.size() - 1, n2 = num2.size() - 1, add = 0;
        string ans;
        while (n1 >= 0 || n2 >= 0) {
            int op1 = 0, op2 = 0, temp = 0;
            if (n1 >= 0) {
                op1 = num1[n1--] - '0';
            }
            if (n2 >= 0) {
                op2 = num2[n2--] - '0';
            }
            temp = op1 + op2 + add;
            if (temp >= 10) add = 1, temp -= 10;
            else add = 0;
            ans += '0' + temp;
        }
        if (add) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};