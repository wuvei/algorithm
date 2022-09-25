class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for (int e: nums) {
            if ((e & 1) == 0) {
                sum += e;
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q: queries) {
            int temp = nums[q[1]];
            nums[q[1]] += q[0];
            if (nums[q[1]] & 1) {
                if ((temp & 1) == 0) {
                    sum -= temp;
                }
            }
            else {
                if (temp & 1) {
                    sum += nums[q[1]];
                }
                else {
                    sum += q[0];
                }
            }
            ans.push_back(sum);
        }
        return std::move(ans);
    }
};