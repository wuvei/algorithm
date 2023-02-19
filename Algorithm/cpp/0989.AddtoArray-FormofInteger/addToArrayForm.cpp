class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0, idx = num.size() - 1;
        while (k || carry) {
            int t = carry + (idx >= 0 ? num[idx] : 0) + (k > 0 ? k % 10 : 0);
            if (t >= 10) {
                carry = 1;
                t -= 10;
            }
            else {
                carry = 0;
            }
            if (idx >= 0) num[idx--] = t;
            else num.insert(num.begin(), t);
            if (k) k /= 10;
        }
        return num;
    }
};