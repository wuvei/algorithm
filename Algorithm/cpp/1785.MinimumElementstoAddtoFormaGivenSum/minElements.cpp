class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long need = goal - sum;
        return (std::abs(need) + limit - 1) / limit;
    }
};