class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return vector<vector<int>>(intervals);
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        int s1 = intervals[0][0], e1 = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > e1) {
                ret.push_back(vector<int>({s1, e1}));
                s1 = intervals[i][0];
            }
            e1 = std::max(intervals[i][1], e1);
        }
        ret.push_back(vector<int>({s1, e1}));
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ret;
        for (auto &i : intervals) {
            if (ret.empty() || i[0] > ret.back()[1]) ret.push_back(i);
            else ret.back()[1] = max(i[1], ret.back()[1]);
        }
        return ret;
    }
};