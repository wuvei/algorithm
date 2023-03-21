class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, cont = 0;
        for (int e : nums) {
            if (e) {
                if (cont) {
                    ans += (cont + 1) * cont >> 1;
                    cont = 0;
                }
            } else ++cont;
        }
        if (cont)
            ans += (cont + 1) * cont >> 1;
        return ans;
    }
};