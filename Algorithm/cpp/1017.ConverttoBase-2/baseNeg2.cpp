class Solution {
public:
    string baseNeg2(int n) {
        if(!n) return "0";
        string ans = "";
        while(n) {
            ans += (n & 1) + '0';
            n = - (n >> 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};