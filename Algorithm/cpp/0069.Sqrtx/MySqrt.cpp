class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int div = x / mid;
            if (mid == div) return mid;
            else if (mid > div) r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }

    // Newton-Raphson
    int mySqrt(int n) {
        int x = n, y = 1;
        // float e = 0.000001; // this is the error
        while(x - y > 0){
            x = x + (x - y) / 2;
            y = n / x;
        }
        return x;
    }

};