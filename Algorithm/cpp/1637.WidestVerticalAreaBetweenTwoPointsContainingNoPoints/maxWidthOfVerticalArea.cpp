class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0, j = 0; j < points.size(); ++j) {
            if (points[j][0] == points[i][0]) continue;
            ans = std::max(ans, points[j][0] - points[i][0]);
            i = j;
        }
        return ans;
    }
};