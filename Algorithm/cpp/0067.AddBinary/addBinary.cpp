class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int l1 = a.size() - 1, l2 = b.size() - 1, add = 0;
        while (l1 >= 0 || l2 >= 0) {
            int op1 = 0, op2 = 0, temp;
            if (l1 >= 0) op1 = a[l1--] - '0';
            if (l2 >= 0) op2 = b[l2--] - '0';
            temp = op1 + op2 + add;
            if (temp > 1) {
                add = 1;
                temp -= 2;
            }
            else add = 0;
            ans += '0' + temp;
        }
        if (add) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};