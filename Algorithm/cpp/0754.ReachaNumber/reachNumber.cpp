class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) target = -target;
        int n = static_cast<int>(std::sqrt(target << 1)), sum = (n * (n + 1)) >> 1;
        while (sum < target || (sum - target) & 1) {
            sum += n + 1;
            ++n;
        }
        return n;
    }
};