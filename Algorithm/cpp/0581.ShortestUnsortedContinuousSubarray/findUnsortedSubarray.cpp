class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), temp = nums[0];
        vector<int> leftMax(n), rightMin(n);
        leftMax[0] = nums[0];
        for (int i = 1; i < n; ++i)
            leftMax[i] = std::max(leftMax[i - 1], nums[i]);
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
            rightMin[i] = std::min(rightMin[i + 1], nums[i]);
        int l = 0, r = n - 1;
        for (; rightMin[l] == nums[l] && l < r; ++l);
        for (; leftMax[r] == nums[r] && l < r; --r);
        if (l == r) return 0;
        return r - l + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for (int i = 0; i < n; i++) {
            if (maxn > nums[i]) right = i;
            else maxn = nums[i];
            
            if (minn < nums[n - i - 1]) left = n - i - 1;
            else minn = nums[n - i - 1];
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leet-yhlf/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。