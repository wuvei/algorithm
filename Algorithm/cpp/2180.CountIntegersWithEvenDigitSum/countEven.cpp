class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        bool even = true;
        for (int i = 2; i <= num; ++i) {
            if (!(i % 10)) {
                int temp = i, sum = 0;
                while (temp) {
                    sum += temp % 10;
                    temp /= 10;
                }
                even = (sum & 1) == 0;
            }
            if (even) ++ans;
            even = !even;
        }
        return ans;
    }
};