class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long l = std::ceil(std::accumulate(quantities.begin(), quantities.end(), 0LL) * 1.0 / n), r = *std::max_element(quantities.begin(), quantities.end());
        while (l < r) {
            long long mid = l + (r - l) / 2, temp = 0;
            for (int q: quantities) {
                temp += std::ceil(q*1.0 / mid);
            }
            if (temp <= n) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};