class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = nums[0], cnt = 1, i = 1;
        while (i < nums.size()) {
            if (last == nums[i]) cnt++;
            else {
                last = nums[i];
                cnt = 1;
            }
            if (cnt > 2) {
                nums.erase(nums.begin() + i);
                cnt = 2;
            }
            else ++i;
        }
        return nums.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = nums[0], cnt = 1, i = 1, j = 1;
        for (; i < nums.size(); i++) {
            if (last == nums[i]) cnt++;
            else {
                last = nums[i];
                cnt = 1;
            }
            if (cnt > 2) {
                cnt = 2;
            }
            else nums[j++] = nums[i];
        }
        return j;
    }
};