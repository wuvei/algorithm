class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> count;
        for (int e: nums) {
            if (!(e & 1)) {
                ++count[e];
            }
        }
        if (count.empty()) {
            return -1;
        }
        int max_count = 0, ans = 0;
        for (auto it: count) {
            if (max_count < it.second) {
                max_count = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};