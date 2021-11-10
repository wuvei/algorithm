class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0, temp;

        for (int num : nums)
        {
            temp = a;
            a = (a ^ num) & b;
            b = ((~temp) & num) | ((~num) & b);
        }

        return b;
    }
};

// 状态机
// a b num |   a' b' 
// 0 0 0   |   0  0
// 0 1 0   |   0  1
// 1 1 0   |   1  1
// 0 0 1   |   0  1
// 0 1 1   |   1  1
// 1 1 1   |   0  0