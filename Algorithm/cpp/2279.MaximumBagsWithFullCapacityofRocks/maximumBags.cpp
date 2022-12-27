class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> remain(n);
        for (int i = 0; i < n; ++i) {
            remain[i] = capacity[i] - rocks[i];
        }
        sort(remain.begin(), remain.end());
        int ans = 0;
        for (int i = 0; i < n && additionalRocks > 0; ++i) {
            if (remain[i] == 0) ++ans;
            else {
                additionalRocks -= remain[i];
                if (additionalRocks >= 0) ++ans;
            }
        }
        return ans;
    }
};