class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> ret;
        if (!length || length < k) return ret;
        deque<int> index;
        
        int currentMax = nums[0];
        index.push_back(0);
        for (int i = 1; i < k; i++) {
            while (!index.empty() && nums[index.back()] < nums[i]) index.pop_back();
            index.push_back(i);
        }
        ret.push_back(nums[index.front()]);
        for (int i = k; i < length; i++) {
            while (!index.empty() && nums[index.back()] < nums[i]) index.pop_back();
            index.push_back(i);
            if (i - index.front() == k) index.pop_front();
            ret.push_back(nums[index.front()]);
        }
        return ret;
    }
};