class Solution {
public:
    int countOdds(int low, int high) {
        if ((low & 1) || (high & 1))
            return ((high - low) >> 1) + 1;
        else return (high - low) >> 1;
    }
};