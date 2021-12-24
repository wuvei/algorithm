class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.clear();
        backtracking(nums, 0);
        return ans;
    }

    void backtracking(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> sw;
        sw.emplace(nums[idx]);
        backtracking(nums, idx + 1);
        for (int i = idx + 1; i < nums.size(); i++) {
            if (sw.find(nums[i]) != sw.end()) continue;
            sw.emplace(nums[i]);
            swap(nums[i], nums[idx]);
            backtracking(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
private:
    vector<vector<int> > ans;
};