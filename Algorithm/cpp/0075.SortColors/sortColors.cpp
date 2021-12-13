class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {};
        for (int n: nums) count[n]++;
        int i = 0, j = 0;
        while (i < nums.size() && j < 3) {
            while (count[j]--)
                nums[i++] = j;
            j++;
        }
    }
};