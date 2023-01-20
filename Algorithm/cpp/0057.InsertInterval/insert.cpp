class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = 0, n = intervals.size();
        while (idx < n && intervals[idx][1] < newInterval[0]) {
            ans.push_back(intervals[idx++]);
        }
        int l = newInterval[0], r = newInterval[1];
        while (idx < n && intervals[idx][0] <= r) {
            l = std::min(intervals[idx][0], l);
            r = std::max(intervals[idx++][1], r);
        }
        ans.push_back({l, r});
        while (idx < n) {
            ans.push_back(intervals[idx++]);
        }
        return ans;
    }
};