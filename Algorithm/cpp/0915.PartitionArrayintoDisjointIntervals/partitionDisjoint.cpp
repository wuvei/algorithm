class Solution {
public:
    int partitionDisjoint(std::vector<int>& nums) {
        const int n = nums.size();
        int partition_idx = 0, pre_max = nums[0], cur_max = pre_max;
        for (int i = 1; i < n; ++i) {
            cur_max = std::max(cur_max, nums[i]);
            if (nums[i] < pre_max) {
                pre_max = cur_max;
                partition_idx = i;
            }
        }
        return partition_idx + 1;
    }
};