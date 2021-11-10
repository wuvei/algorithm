class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        vector<int> re(2);
        int intermediate = 0;
        for (int e: nums) {
            intermediate ^= e;
        }
        intermediate = intermediate & (~intermediate + 1);
        for (int e: nums) {
            if (intermediate & e) re[1] ^= e;
            else re[0] ^=e;
        }
        return re;
    }
};