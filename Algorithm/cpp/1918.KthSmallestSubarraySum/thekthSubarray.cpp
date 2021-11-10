class Solution {
public:
    /**
     * @param a: an array
     * @param k: the kth
     * @return: return the kth subarray
     */
    long long thekthSubarray(vector<int> &a, long long k) {
        vector<long long> pre_sum(a.size() + 1, 0);
        for (int i = 1; i < pre_sum.size(); i++) {
            pre_sum[i] = pre_sum[i - 1] + a[i - 1];
        }
        long long l = 0, r = pre_sum.back();
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (smallerOrEqual(pre_sum, mid) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    long long smallerOrEqual(vector<long long> &pre_sum, long long v) {
        long long sum = 0;
        for (int i = 0, j = 1; i < pre_sum.size() - 1; i++) {
            while (j < pre_sum.size() && pre_sum[j] - pre_sum[i] <= v) j++;
            sum += j - i - 1;
        }
        return sum;
    }
};