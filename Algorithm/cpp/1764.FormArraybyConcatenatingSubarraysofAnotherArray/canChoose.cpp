class Solution {
    vector<int> getlps(vector<int> v) {
        int n=v.size();
        vector<int> lps(n, 0);
        int i = 1, ptr = 0;
        while (i < n) {
            if (v[i] == v[ptr]) {
                ++ptr;
                lps[i] = ptr;
                ++i;
            }
            else {
                if (ptr != 0) ptr = lps[ptr - 1];
                else ++i;
            }
        }
        return lps;
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size(), i = 0, j = 0;
        while (i < n && j < nums.size()) {
            vector<int> lps = getlps(groups[i]);
            int ptr1 = 0, ptr2 = j;
            while(ptr1 < groups[i].size() && ptr2 < nums.size()) {
                if(groups[i][ptr1] == nums[ptr2]) {
                    ++ptr1;
                    ++ptr2;
                }
                else {
                    if (ptr1 != 0) ptr1 = lps[ptr1 - 1];
                    else ++ptr2;
                }
            }
            if(ptr1 < groups[i].size()) return false;
            ++i;
            j = ptr2;
        }
        return i == n;
    }
};
