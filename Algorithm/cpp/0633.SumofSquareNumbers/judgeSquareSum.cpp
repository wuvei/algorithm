class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        while(l <= r) {
            long long temp = l * l + r * r;
            if (temp == c) return true;
            else if (temp < c) l++;
            else r--;
        }
        return false;
    }
};