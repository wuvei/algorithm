class Solution {
public:
    int reinitializePermutation(int n) {
        if (n <= 4) return n >> 1;
        int ans = 1, half = n >> 1, i = half;
        while (i != 1) {
            if (i & 1) i = half + ((i - 1) >> 1);
            else i = i >> 1;
            ++ans;
        }
        return ans;
    }
};