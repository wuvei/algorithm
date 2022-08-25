class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int nums[1001] = {}, count = 0, e1, e2;
        for (int i = 0; i < target.size(); ++i) {
            e1 = target[i];
            e2 = arr[i];
            --nums[e1];
            if (nums[e1] == -1) ++count;
            else if (!nums[e1]) --count;
            ++nums[e2];
            if (nums[e2] == 1) ++count;
            else if (!nums[e2]) --count;
        }
        return !count;
    }
};