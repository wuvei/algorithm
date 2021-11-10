class Solution {
public:
    static int cmp(const void *a, const void *b)
    {
        string a1 = to_string(*(int *)a), b1 = to_string(*(int *)b);
        string s1 = a1 + b1, s2 = b1 + a1;
        if (s1 < s2)
            return -1;
        else if (s1 > s2)
            return 1;
        else
            return 0;
    }
    string minNumber(vector<int>& nums) {
        if (!nums.size()) return string("");
        qsort(&nums[0], nums.size(), sizeof(int), cmp);
        string re;
        for(int num: nums) {
            re += to_string(num);
        }
        return re;
    }
};