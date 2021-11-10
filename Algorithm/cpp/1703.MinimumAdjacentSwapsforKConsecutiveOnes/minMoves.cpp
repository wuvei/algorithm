class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> p;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i]) p.push_back(i);
        
        int sum = 0;
        // calculate the first k pts
        for (int i = 0; i < k; i++)
            sum += std::abs(p[i] - p[k/2]);
        int ans = sum;
        
        for (int i = 0; i + k < p.size(); i++) {
            int mid = i + k/2;
            sum -= abs(p[mid] - p[i]);
            sum += abs(p[mid+1] - p[mid]) * (k/2);
            sum += abs(p[i+k] - p[mid+1]);
            sum -= abs(p[mid+1] - p[mid]) * (k-k/2-1);
            ans = min(ans, sum);
        }
        int offset = 0;
        for (int i=0; i<k; i++)
            offset += abs(i-k/2);
        
        return ans - offset;
    }
};