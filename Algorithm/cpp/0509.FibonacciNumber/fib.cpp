class Solution {
public:
    int fib(int n) {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN / sqrt5);
    }
};

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int f1 = 0, f2 = 1, temp;
        for (int i = 2; i <= n; ++i) {
            temp = f2;
            f2 = f1 + f2;
            f1 = temp;
        }
        return f2;
    }
};

