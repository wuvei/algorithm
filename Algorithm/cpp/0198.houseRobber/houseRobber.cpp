/*
    Dynamic Programming
    d[i]: maximum amount of money from house 0 ~ i
    d[i] = max{d[i - 2]+nums[i], d[i - 1]};
    pre1 & pre2 store d[i-2], d[i-1]
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size(), pre1 = 0, pre2 = 0;
        for(int i = 0; i < len;i++){
            if(i == 0)
                pre2 = pre1 = nums[0];
            else if(i == 1){
                pre2 = max(nums[0], nums[1]);
            }
            else{
                int temp = pre2;
                pre2 = max(nums[i] + pre1, pre2);
                pre1 = temp;
            }
        }
        return pre2;
    }
};