class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freq, freq_count;
        unordered_set<int> s;
        int ans = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int e = nums[i];
            --freq_count[freq[e]];
            if (freq_count[freq[e]] == 0)
                s.erase(freq[e]);
            ++freq[e];
            ++freq_count[freq[e]];
            if (freq_count[freq[e]] == 1)
                s.insert(freq[e]);
            if (s.size() == 1) {
                int count = *s.begin();
                if (count == 1 || freq.size() == 1)
                    ans = i + 1;
            }
            if (s.size() == 2) {
                int sum = accumulate(s.begin(), s.end(), 0);
                for (auto it: s) {
                    if (freq_count[it] == 1 && (it == 1 || it == sum - it + 1))
                        ans = i + 1;
                }
            }  
        }
        return ans;
    }
};