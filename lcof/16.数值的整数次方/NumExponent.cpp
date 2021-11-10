class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0.0 || x == 1.0) return x;
        bool flag = (n < 0);
        if (flag) {
            x = 1.0 / x;
            n = - (n + 1); // for case n = 2^(-31)
        }
        double ans = 1, base = x;
        while (n > 0) {
            if (n & 1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return flag? ans * base: ans;
    }
};