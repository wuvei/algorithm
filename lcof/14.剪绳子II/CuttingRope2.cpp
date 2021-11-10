class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int a = n % 3;
        int b = n / 3;
        if (a == 0) {
            return (int) pow(3, b);
        } else  if (a == 1) {
            return (int) ((pow(3, b - 1) * 4) % 1000000007);
        } else  {
            return (int) ((pow(3, b) * 2) % 1000000007);
        }
    }

private:
    // Binary Exponentiation
    long pow(long base, int exp) {
        long res = 1;
        while (exp > 0) {
            if (exp & 1) {
                res = res * base;
                res %= 1000000007;
            }
            base *= base;
            base %= 1000000007;
            exp >>= 1;
        }
        return res;
    }
};