class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        int max_count = 0;
        for (int e: arr) {
            ++count[e];
            max_count = std::max(count[e], max_count);
        }
        vector<int> freq(max_count + 1, 0);
        for (auto it: count) {
            ++freq[it.second];
        }
        int ans = 0, target = arr.size() >> 1;
        for (int i = max_count; i > 0 && target > 0; --i) {
            int most = (target + i - 1) / i, used = std::min(most, freq[i]);
            target -= used * i;
            ans += used;
        }
        return ans;
    }
};