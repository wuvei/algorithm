class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *std::max_element(piles.begin(), piles.end());
        auto check = [&](int x) {
            int sum = 0;
            for (int p : piles) {
                sum += (p + x - 1) / x;
            }
            return sum <= h;
        };
        int mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};