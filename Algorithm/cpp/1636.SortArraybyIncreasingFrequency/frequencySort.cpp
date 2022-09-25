class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int count[201] = {};
        for (int e: nums) {
            ++count[e + 100];
        }
        map<int, vector<int> > mp;
        for (int i = 200; i >= 0; --i) {
            if (count[i]) {
                mp[count[i]].push_back(i - 100);
            }
        }
        vector<int> ans;
        ans.reserve(nums.size());
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            for (auto e: it->second) {
                for (int i = 0; i < it->first; ++i) {
                    ans.push_back(e);
                }
            }
        }
        return ans;
    }
};