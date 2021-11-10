class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (!k) return vector<int>();
        partition(arr, k, 0, arr.size() - 1);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    void partition(vector<int>& arr, int k, int start, int end) {
        if (start >= end) return;
        int l = start, r = end, pivot = arr[start];
        while (l < r) {
            while (l < r && arr[r] >= pivot) r--;
            while (l < r && arr[l] <= pivot) l++;
            if (l < r) swap(arr[l], arr[r]);
        }
        arr[start] = arr[l];
        arr[l] = pivot;
        if (l < k) partition(arr, k, l + 1, end);
        else if (l > k) partition(arr, k, start, l - 1);
    }
};