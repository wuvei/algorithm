#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0], ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp = dp <= 0? nums[i]: dp + nums[i];
            ret = std::max(dp, ret);
        }
        return ret;
    }

    // Print the max subarray (leftmost)
    int maxSubArray2(vector<int>& nums) {
        int dp = nums[0], ret = nums[0], mem[2] = {}, idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (dp <= 0) {
                dp = nums[i];
                idx = i;
            }
            else dp += nums[i];
            if (ret < dp) {
                ret = dp;
                mem[0] = idx;
                mem[1] = i;
            }
            ret = std::max(dp, ret);
        }
        for (int i = mem[0]; i <= mem[1]; i++)
            cout << nums[i] << " ";
        cout << endl;
        return ret;
    }
    // divide and conquer
    int divide(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        int mid = (start + end) >> 1;
        int leftMax = divide(nums, start, mid), rightMax = divide(nums, mid + 1, end);
        int leftBorderSum = nums[mid], leftMaxBorderSum = nums[mid];
        int rightBorderSum = nums[mid + 1], rightMaxBorderSum = nums[mid + 1];
        for (int i = mid - 1; i >= start; i--) {
            leftBorderSum += nums[i];
            if (leftMaxBorderSum < leftBorderSum) leftMaxBorderSum = leftBorderSum;
        }
        for (int i = mid + 2; i <= end; i++) {
            rightBorderSum += nums[i];
            if (rightMaxBorderSum < rightBorderSum) rightMaxBorderSum = rightBorderSum;
        }
        return max({leftMax, rightMax, leftMaxBorderSum + rightMaxBorderSum});
    }
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return divide(nums, 0, nums.size() - 1);
    }
};

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> b(a, a + sizeof(a) / sizeof(int));
    Solution s;
    int ret = s.maxSubArray2(b);
    cout << ret << endl;
    return 0;
}