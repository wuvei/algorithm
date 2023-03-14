class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = *std::min_element(time.begin(), time.end()), r = l * totalTrips;
        auto check = [&](long long t) {
            int sum = 0;
            for (int e : time) {
                sum += t / e;
                if (sum >= totalTrips)
                    return true;
            }
            return false;
        };
        while (l < r) {
            long long mid = l + ((r - l) >> 1);
            if (check(mid)) {
                r = mid;
            }
            else l = mid + 1;
        }
        return l;
    }
};