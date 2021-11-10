class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (smallerOrEqual(m, n, mid) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    int smallerOrEqual(int m, int n, int v) {
        // int sum = 0, i = m, j = 1;
        // while (j <= n) {
        //     if (i >= 1 && i * j > v) i--;
        //     else {
        //         sum += i;
        //         j++;
        //     }
        // }
        // return sum;
        int sum = 0;
        for (int i = 1; i <= m; i++) {
            sum += std::min(v / i, n);
        }
        return sum;
    }
};