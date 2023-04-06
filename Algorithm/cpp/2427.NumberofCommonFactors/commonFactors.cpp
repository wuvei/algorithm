class Solution {
public:
    int commonFactors(int a, int b) {
        int gcdVal = std::gcd(a, b);
        if (gcdVal == 1) return 1;
        int ans = 2, x = 2;
        for (; x * x < gcdVal; ++x) {
            if (gcdVal % x == 0)
                ans += 2;
        }
        ans += x * x == gcdVal;
        return ans;
    }
};