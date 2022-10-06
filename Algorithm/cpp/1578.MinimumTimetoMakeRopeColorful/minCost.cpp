class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, sum = neededTime[0], repeat_max = neededTime[0], repeat_count = 1;
        for (int i = 1; i < neededTime.size(); ++i) {
            if (colors[i] == colors[i - 1]) {
                sum += neededTime[i];
                repeat_max = std::max(repeat_max, neededTime[i]);
                ++repeat_count;
            }
            else {
                if (repeat_count > 1) {
                    ans += sum - repeat_max;
                }
                sum = neededTime[i];
                repeat_max = neededTime[i];
                repeat_count = 1;
            }
        }
        if (repeat_count > 1) {
            ans += sum - repeat_max;
        }
        return ans;
    }
};