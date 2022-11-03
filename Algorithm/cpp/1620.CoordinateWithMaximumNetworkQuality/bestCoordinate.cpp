class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int max_x = INT_MIN, max_y = INT_MIN;
        for (auto &t: towers){
            max_x = max(max_x, t[0]);
            max_y = max(max_y, t[1]);
        }
        int best_total_q = INT_MIN;
        vector<int> ans;
        for (int x = 0; x <= max_x; ++x) {
            for (int y = 0; y <= max_y; ++y) {
                int total_q = 0;
                for (auto &t: towers){
                    double dis = sqrt((x - t[0]) * (x - t[0]) + (y - t[1]) * (y - t[1]));
                    if (dis <= radius){
                        total_q += static_cast<int>(t[2] / (1.0 + dis));
                    }
                }
                if (total_q > best_total_q){
                    best_total_q = total_q;
                    ans = {x, y};
                }         
            }
        }
        return ans;     
    }
};