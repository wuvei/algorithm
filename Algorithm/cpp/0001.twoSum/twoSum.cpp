class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> result;
        for(int i = 0; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                ans[0] = m[target - nums[i]];
                ans[1] = i;
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};