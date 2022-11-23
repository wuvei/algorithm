class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int count[46] = {};
        auto f = [](int t) -> int {
            int s = 0;
            while (t) {
                s += t % 10;
                t /= 10;
            }
            return s;
        };
        int sum = f(lowLimit);
        while (lowLimit <= highLimit) {
            ++count[sum];
            ++lowLimit;
            ++sum;
            if (lowLimit % 10 == 0) {
                sum = f(lowLimit);
            }
        }
        int ans = 0;
        for (int i = 0; i < 46; ++i) {
            ans = std::max(ans, count[i]);
        }
        return ans;
    }
};