// 1. Sort
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2);
        int n = nums.size(), t = (1 + n) * n / 2;
        t -= nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ans[0] = nums[i];
            }
            else t -= nums[i];
        }
        ans[1] = t;
        return ans;
    }
};

// 2. Hash
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), sum = (1 + n) * n / 2, x = 0;
        for(int i = 0; i < n; i++) {     
            while(nums[i] - 1 != i && !x) {
                if(nums[nums[i] - 1] == nums[i]) x = nums[i];
                swap(nums[nums[i] - 1], nums[i]);
            }
            sum -= nums[i];
        }
        return {x, sum + x};
    }
};

// 作者：L-Sheng
// 链接：https://leetcode.cn/problems/set-mismatch/solution/shu-zu-xia-biao-fang-fa-by-liang-sheng-1-i2cm/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 3. Bit
// TODO