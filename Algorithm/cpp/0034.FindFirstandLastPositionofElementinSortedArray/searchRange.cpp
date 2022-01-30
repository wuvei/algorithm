class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
    
        int l = 0, r = nums.size() - 1; //二分范围
        while( l < r)                   //查找元素的开始位置
        {
            int mid = (l + r )/2;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if( nums[r] != target) return {-1,-1};  //查找失败
        int L = r;
        l = 0, r = nums.size() - 1;     //二分范围
        while( l < r)                   //查找元素的结束位置
        {
            int mid = (l + r + 1)/2;
            if(nums[mid] <= target ) l = mid;
            else r = mid - 1;
        }
        return {L,r};
    }
};

// binary search template
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/tu-jie-er-fen-zui-qing-xi-yi-dong-de-jia-ddvc/