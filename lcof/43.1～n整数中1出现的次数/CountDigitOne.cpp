class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1;
        // digit needs to be long type: when n = INT_MAX, digit will overflow in the last iter
        int high = n / 10, cur = n % 10, low = 0;
        int res = 0;

        while (high != 0 || cur != 0) {
            if (cur == 0) {
                res += high * digit;
            }
            else if (cur == 1) {
                res += high * digit + low + 1;
            }
            else {
                res += (high + 1) * digit;
            }

            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10; 
        }

        return res;
    }
};

// https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/zi-jie-ti-ku-jian-43-kun-nan-1n-zheng-shu-zhong-1-/
