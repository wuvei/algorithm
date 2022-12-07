class Solution {
public:
    
    int ans = 100000, diff = 100000, t;
    
    void helper(vector<int>& toppingCosts, int currSum, int index) {
        int currDiff = abs(t - currSum);
        if (diff < currSum - t) {
            return;
        } else if (diff >= currDiff) {
            if (diff > currDiff) {
                ans = currSum;
                diff = currDiff;
            } else {
                ans = min(ans, currSum);
            }
        }

        if(index == toppingCosts.size()) return;
        
        helper(toppingCosts, currSum, index + 1);
        helper(toppingCosts, currSum + toppingCosts[index], index + 1);
        helper(toppingCosts, currSum + 2 * toppingCosts[index], index + 1);
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        t = target;
        for (int base: baseCosts)
            helper(toppingCosts, base, 0);
        
        return ans;
    }
};