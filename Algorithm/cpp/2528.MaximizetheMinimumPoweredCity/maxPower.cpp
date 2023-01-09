class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n + 1, 0), elec(n, 0), diff(n, 0);
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i - 1] + stations[i - 1];
        for (int i = 0; i < n; ++i) 
            elec[i] = prefix[std::min(n, i + r + 1)] - prefix[std::max(0, i - r)];
        
        auto check = [&](long long min_power) -> bool {
            std::fill(diff.begin(), diff.end(), 0);
            long sum_d = 0, need = 0;
            for (int i = 0; i < n; ++i) {
                sum_d += diff[i]; 
                long m = min_power - elec[i] - sum_d;
                if (m > 0) { // need m
                    need += m;
                    if (need > k) return false;
                    sum_d += m; // accumulate diff
                    if (i + r * 2 + 1 < n) diff[i + r * 2 + 1] -= m; // update diff
                }
            }
            return true;
        };

        long long left = -1, right = prefix[n] + k + 1;
        while (left + 1 < right) {
            long long mid = (left + right) >> 1;
            if (check(mid)) left = mid;
            else right = mid;
        }
        return left;
    }
};