class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int prev_max = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (prev_max > nums[i])
                return false;
            prev_max = std::max(prev_max, nums[i - 1]);
        }
        return true;
    }
};

// Consider permutation [1 .. n]
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (std::abs(nums[i] - i) >= 2) return false;
        }
        return true;
    }
};