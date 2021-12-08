class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size() - 1;
        if (n >= hour) return -1;
        int l = 1, r = std::max(*std::max_element(dist.begin(), dist.end()), int(std::ceil(dist[n] / (hour - n))));
        while (l < r) {
            int mid = l + (r - l) / 2;
            double temp = 0;
            for (int i = 0; i < n; i++)
                temp += std::ceil(1.0*dist[i] / mid);
            temp += 1.0 * dist[n] / mid;
            if (temp <= hour) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};