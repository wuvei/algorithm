class Solution {
public:
    // 波义尔摩尔投票算法（Boyer-Moore Voting Algorithm）
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], count = 0;
        for (int e: nums) {
            if (!count) {
                maj = e;
                count++;
            }
            else (maj == e)? count++: count--;
        }
        return maj;
    }
};