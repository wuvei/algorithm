class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, left = 0, totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            left += gas[i] - cost[i];
            if (left < 0) {
                start = i + 1;
                left = 0;
            }
        }
        if (totalGas < totalCost) {
            return -1;
        }
        return start;
    }
};