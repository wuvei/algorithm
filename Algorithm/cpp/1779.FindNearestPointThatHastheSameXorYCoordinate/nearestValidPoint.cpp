class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1, dis = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            int t = -1;
            if (points[i][0] == x) {
                t = std::abs(y - points[i][1]);
            }
            else if (points[i][1] == y) {
                t = std::abs(x - points[i][0]);
            }
            if (t >= 0 && dis > t) {
                dis = t;
                ans = i;
            }
        }
        return ans;
    }
};