class Solution {
public:
    void Merge(vector<int> &nums, int low, int mid, int high)
    {                                                 
        int i = low, j = mid + 1, k = 0;
        int *temp = new (nothrow) int[high - low + 1];
        while (i <= mid && j <= high)
        {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else {
                temp[k++] = nums[j++];
                pairs += mid - i + 1;
            }
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= high)
            temp[k++] = nums[j++];
        for (i = low, k = 0; i <= high; i++, k++)
            nums[i] = temp[k];
        delete[] temp;
    }

    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int size = 1, low, mid, high, n = nums.size();
        pairs = 0;
        while (size <= n - 1)
        {
            low = 0;
            while (low + size <= n - 1)
            {
                mid = low + size - 1;
                high = mid + size;
                if (high > n - 1)
                    high = n - 1;
                Merge(nums, low, mid, high);
                low = high + 1; 
            }
            size *= 2;
        }
        return pairs;
    }
private:
    int pairs;
};