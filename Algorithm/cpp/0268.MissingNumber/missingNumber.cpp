// xor
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), x;
        switch(n % 4) {
            case 1:
                x = 1;
                break;
            case 2:
                x = n + 1;
                break;
            case 3:
                x = 0;
                break;
            default:
                x = n;
        }
        for (int e: nums)
            x ^= e;
        return x;
    }
};

// plus
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return n * (n + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
    }
};