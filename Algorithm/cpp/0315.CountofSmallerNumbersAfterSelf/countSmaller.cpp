class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        idx.resize(n, 0);
        ans.resize(n, 0);
        temp.resize(n, 0);
        tempIdx.resize(n, 0);
        for (int i = 1; i < n; ++i) idx[i] = i;
        mergeSort(nums, 0, n - 1);
        return ans;
    }
    void mergeSort(vector<int> &a, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
    void merge(vector<int> &a, int l, int mid, int r) {
        int i = l, j = mid + 1, p = l;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) {
                temp[p] = a[i];
                tempIdx[p] = idx[i];
                ans[idx[i]] += j - mid - 1;
                ++i;
            }
            else {
                temp[p] = a[j];
                tempIdx[p] = idx[j];
                ++j;
            }
            ++p;
        }
        while (i <= mid) {
            temp[p] = a[i];
            tempIdx[p] = idx[i];
            ans[idx[i]] += j - mid - 1;
            ++i;
            ++p;
        }
        while (j <= r) {
            temp[p] = a[j];
            tempIdx[p] = idx[j];
            ++j;
            ++p;
        }
        for (int k = l; k <= r; ++k) {
            idx[k] = tempIdx[k];
            a[k] = temp[k];
        }
    }
private:
    vector<int> idx, ans, temp, tempIdx;
};