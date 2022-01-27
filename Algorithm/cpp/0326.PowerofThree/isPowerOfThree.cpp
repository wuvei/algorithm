 // 1162261467 = 3 ^ 19
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

// use log
class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};