class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long l = maxSum / n, r = maxSum - n + 1, part = index * (index - 1LL) / 2LL;
        while (l < r) {
            long long mid = l + (r - l + 1LL) / 2LL, temp = mid;
            if (mid > index) temp += (mid - 1LL) * index - part;
            else temp += mid * (mid - 1LL) / 2LL + index - mid + 1LL;
            if (mid > n - index) temp += (mid - 1LL) * (n - index - 1LL) - (n - index - 1LL) * (n - index - 2LL) / 2LL;
            else temp += mid * (mid - 1LL) / 2LL + n - index - mid;
            if (temp <= maxSum) l = mid;
            else r = mid - 1;
        }
        return int(l);
    }
};

// math

class Solution {
public:
    int maxValue(int n, int left, int maxSum) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int right=n-left-1;
        long low=min(left, right);
        maxSum-=n;//reserve 1 for each position
        if(maxSum < low*low) {
            //     /\
            //   /    \
            // /________\______
            // 0,1,..., low-1, low, low-1, ...1,0, ... 0,0,0
            return 1+sqrt(maxSum);
        }
        long high=max(left, right);
        long val=high*high-(high-low)*(high-low-1)/2;
        if(maxSum < val) {
            //    /\
            //  /    \
            // |       \
            // |_________\
            // high-low, high-low+1, ..., high-1, high, high-1, ..., 2,1, 0
            return 1+sqrt(2*maxSum+2*(low+0.5)*(low+0.5)-0.25)-low-0.5;
        }
        //    /\
        //  /    \
        // |       \
        // |        |
        // |________|
        return 1+high+(maxSum-val)/n;
    }
};