class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int half = (nums.size() - 1) / 2;
        vector<int> lsum = getSum(nums, 0, half);
        vector<int> rsum = getSum(nums, half + 1, nums.size() - 1);
        
        int ans = INT_MAX;
        for (auto i = lsum.begin(); i != lsum.end(); ++i) {
            auto it = lower_bound(rsum.begin(), rsum.end(), goal - *i);
            if (it == rsum.begin()) {
                ans = min(ans, abs(goal - (*i + *it)));
            } else if (it == rsum.end()) {
                ans = min(ans, abs(goal - (*i + *(it - 1))));
            } else {
                ans = min(ans, abs(goal - (*i + *it)));
                ans = min(ans, abs(goal - (*i + *(it - 1))));
            }
        }
        return ans;

    }
    
    vector<int> getSum(vector<int>& nums, int l, int r) {
        vector<int> sum({0});
        for (int idx = l; idx <= r; idx++) {
            vector<int> temp;
            int x = nums[idx], n = sum.size();
            for(int i = 0, j = 0; i < n || j < n;) {
                if (i == n) temp.push_back(sum[j++] + x);
                else if (j == n) temp.push_back(sum[i++]);
                else if (sum[i] < sum[j] + x) temp.push_back(sum[i++]);
                else temp.push_back(sum[j++] + x);
            }
            sum = temp;
        }
        return sum;
    }
};