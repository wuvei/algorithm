class Solution {
public:
    int climbStairs(int n) {
        if (n > 0) {
            double square_root_5 = sqrt((double)5);
            return (pow((1 + square_root_5), (double)(n + 1)) - pow((1 - square_root_5), (double)(n + 1))) / (pow((double)2, (double)(n + 1))*square_root_5);
        }
        return 1;
    }
};

// From https://blog.csdn.net/liu798675179/article/details/52328596