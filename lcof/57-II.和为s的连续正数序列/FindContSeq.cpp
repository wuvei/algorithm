class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> re;
        if (target < 5)
        {
            if (target == 3)
                re.push_back(vector<int>{1, 2});
            return re;
        }
        for (long i = target / 2 + 1; i >= 2; i--)
        {
            long long a = 2 * target - i * i + i, b = 2 * i;
            if (a <= 0)
                continue;
            if (a % b == 0)
            {
                vector<int> temp;
                int end = a / b + i;
                for (int j = a / b; j < end; j++)
                    temp.push_back(j);
                re.push_back(temp);
            }
        }
        return re;
    }
};