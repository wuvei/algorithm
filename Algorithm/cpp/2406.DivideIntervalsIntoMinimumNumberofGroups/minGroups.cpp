class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
        });
        multiset<int> s;
        s.insert(intervals[0][0]);
        for (int i = 1; i < intervals.size(); ++i) {
            auto &v = intervals[i];
            auto it = s.upper_bound(v[1]);
            if (it != s.end()) {
                s.erase(it);
            }
            s.insert(v[0]);
        }
        return s.size();
    }
};