class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i <= n - 3; ++i) {
            int j = i + 1, k = n - 1, sum;
            while (j < k) {
                int min = nums[i] + nums[j] + nums[j + 1];
                if(target < min){
                    if(abs(ans - target) > abs(min - target))
                        ans = min;
                    break;
                }
                int max = nums[i] + nums[k] + nums[k - 1];
                if(target > max){
                    if(abs(ans - target) > abs(max - target))
                        ans = max;
                    break;  
                }

                sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }
                if (std::abs(target - sum) < std::abs(target - ans)) {
                    ans = sum;
                }
                if (target > sum) {
                    ++j;
                    while(j < k && nums[j] == nums[j - 1])
                        ++j;
                    
                }
                else {
                    --k;
                    while(j < k && nums[k] == nums[k + 1])
                        --k;
                } 
            }
            while(i < n - 2 && nums[i] == nums[i + 1])
                ++i;
        }
        return ans;
    }
};
// https://leetcode.cn/problems/3sum-closest/solution/dui-shuang-zhi-zhen-fa-jin-xing-yi-dian-you-hua-da/