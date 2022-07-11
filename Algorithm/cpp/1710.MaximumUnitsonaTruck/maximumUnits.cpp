class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] == b[1] ? a[0] < b[0]: a[1] > b[1];
        });
        int ans = 0;
        for (auto &v: boxTypes) {
            int temp = min(truckSize, v[0]);
            ans += temp * v[1];
            truckSize -= temp;
            if (truckSize == 0) break;
        }
        return ans;
    }
};