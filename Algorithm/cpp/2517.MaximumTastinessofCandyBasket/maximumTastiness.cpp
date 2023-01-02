class Solution {
public:
    int n;
    bool check(vector<int>& price, int mid, int k) {
        int count = 1, pre = price[0];
        for (int i = 1; i < n; ++i) {
            if (price[i] >= pre + mid) {
                ++count;
                pre = price[i];
            }
            if(count == k) return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        n = price.size();
        sort(price.begin(), price.end());
        if (k == 2) return price[n - 1] - price[0];
        int l = 0, r = (price[n - 1] - price[0]) / (k - 1) + 1;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            if (check(price, mid, k)) l = mid;
            else r = mid;
        }
        return l;
    }
};