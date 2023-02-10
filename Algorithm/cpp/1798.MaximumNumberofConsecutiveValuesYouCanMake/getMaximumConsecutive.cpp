
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        for(int c : coins) {
           if(c > ans + 1) break;
           ans += c;
        }
        return ans + 1;
    }
};
