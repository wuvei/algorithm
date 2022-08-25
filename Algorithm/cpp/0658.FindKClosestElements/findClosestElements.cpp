class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == arr.size())
            return arr;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.begin())
            return vector<int>(arr.begin(), arr.begin() + k);
        else if (it == arr.end())
            return vector<int>(arr.end() - k, arr.end());
        int r = it - arr.begin(), l = r - 1;
        while (k--) {
            if (l < 0) ++r;
            else if (r >= arr.size()) --l;
            else if (arr[r] - x < x - arr[l])
                ++r;
            else --l;
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};