class Solution {
public:
    int fillCups(vector<int>& amount) {
        int Max = std::max(std::max(amount[0], amount[1]), amount[2]), Sum = amount[0] + amount[1] + amount[2], diff = Sum - Max - Max;
        return Max + (diff > 0 ? (diff + 1) / 2: 0);
    }
};