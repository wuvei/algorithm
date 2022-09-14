class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int trim = arr.size() * 0.05, sum = 0;
        for (int i = trim; i < arr.size() - trim; ++i) {
            sum += arr[i];
        }
        return 1.0 * sum / (arr.size() - 2 * trim);
    }
};