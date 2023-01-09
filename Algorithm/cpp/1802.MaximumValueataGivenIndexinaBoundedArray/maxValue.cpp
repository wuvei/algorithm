class Solution {
public:
    long long sum(int val, int count) {
        if (val >= count)
            return (1LL + val - count + val) * count / 2;
        else return (val + 1LL) * val / 2 + count - val;
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);
            if (sum(mid - 1, index) + sum(mid, n - index) <= maxSum)
                l = mid;
            else r = mid - 1;
        }
        return l;
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