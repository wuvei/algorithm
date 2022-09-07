// O(n)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums);
        for (int i = 0, j = -1; i < n; ++i) {
            ans[++j] = nums[i];
            ans[++j] = nums[i + n];
        }
        return ans;
    }
};

// O(1)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = 0, j = -1; i < n; ++i) {
            nums[++j] |= (nums[i] & 1023) << 10;
            nums[++j] |= (nums[i + n] & 1023) << 10;
        }
        for(int& e: nums) e >>= 10;
        return nums;
    }
};

