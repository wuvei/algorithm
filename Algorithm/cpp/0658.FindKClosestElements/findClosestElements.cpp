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


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        if(arr.size() == k) return arr;
        while(left+1 < right){
            int mid = left + (right - left) / 2;
            if(x - arr[mid] > arr[mid + k] - x) left = mid;
            else right = mid;
        }
        if(x-arr[left] <= arr[left + k] - x){
            return vector<int>(arr.begin() + left, arr.begin() + left + k);
        }
        else if(x-arr[left] > arr[left + k] - x){
            return vector<int>(arr.begin() + left + 1 , arr.begin() + left + k + 1);
        }
        else return arr;
    }
};