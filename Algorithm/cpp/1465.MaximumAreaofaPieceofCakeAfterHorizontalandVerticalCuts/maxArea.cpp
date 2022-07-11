class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hmax = std::max(horizontalCuts[0], h - horizontalCuts.back()), vmax = std::max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); ++i)
            hmax = std::max(hmax, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < verticalCuts.size(); ++i)
            vmax = std::max(vmax, verticalCuts[i] - verticalCuts[i - 1]);
        return static_cast<int>(1LL * static_cast<long long>(hmax) * static_cast<long long>(vmax) % (1000000007));
    }
};