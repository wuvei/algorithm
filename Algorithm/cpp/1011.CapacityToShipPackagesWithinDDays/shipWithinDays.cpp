class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = std::accumulate(weights.begin(), weights.end(), 0);
        int l = std::max(r / days, *std::max_element(weights.begin(), weights.end()));
        auto check = [&](int v) {
            int cnt = 1, sum = 0;
            for (int w: weights) {
                if (sum + w > v) {
                    ++cnt;
                    sum = w;
                }
                else sum += w;
            }
            return cnt <= days;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};