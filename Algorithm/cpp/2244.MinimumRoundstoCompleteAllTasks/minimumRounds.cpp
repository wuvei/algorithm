class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> count;
        for (int t: tasks) ++count[t];
        int ans = 0;
        for (auto &it: count) {
            if (it.second == 1) return -1;
            ans += it.second / 3 + (it.second % 3 > 0);
        }
        return ans;
    }
};