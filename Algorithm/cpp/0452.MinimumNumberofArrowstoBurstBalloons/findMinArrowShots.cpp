class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1, prevl = points[0][0], prevr = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            auto &p = points[i];
            if (p[0] <= prevr) {
                prevl = p[0];
                prevr = std::min(p[1], prevr);
            }
            else { // a new arrow
                prevl = p[0];
                prevr = p[1];
                ++ans;
            }
        }
        return ans;
    }
};