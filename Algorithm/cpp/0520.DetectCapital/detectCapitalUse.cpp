class Solution {
public:
    bool detectCapitalUse(string& word) {
        uint8_t count = 0;
        for (char& c : word) {
            count += ~c>>5&1;
        }
        return count == word.size() || count == 0 || ~word[0]>>5&1 && count == 1;
    }
};

// https://leetcode.com/problems/detect-capital/solutions/2983290/c-bit-manipulation-branchless-programming-time-100-mem-90/