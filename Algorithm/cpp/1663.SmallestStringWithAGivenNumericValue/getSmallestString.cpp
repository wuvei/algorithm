class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        --n;
        while (k > 25) {
            ans[n--] = 'z';
            k -= 25;
        }
        ans[n] = 'a' + k;
        return ans;
    }
};