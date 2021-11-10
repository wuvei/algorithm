class Solution {
public:

    void adjust(vector<int>& nums, int len, int index)
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int maxIdx = index;
        if(left < len && nums[left] > nums[maxIdx]) maxIdx = left;
        if(right < len && nums[right] > nums[maxIdx]) maxIdx = right;  // maxIdx is the largest index among these 3.
        if(maxIdx != index)                 // If maxIdx updated
        {
            swap(nums[maxIdx], nums[index]);
            adjust(nums, len, maxIdx);       // Recursively heapify the affected sub-tree
        }

    }

    // Heap Sort
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() < 2) return vector<int>(nums);
        int size = nums.size();
        for(int i = size/2 - 1; i >= 0; i--)  // From last non-leaf node, adjust the heap
        {
            adjust(nums, size, i);
        }
        for(int i = size - 1; i >= 1; i--)
        {
            swap(nums[0], nums[i]);           // Move current root to end
            adjust(nums, i, 0);              // Recursively heapify the affected sub-tree
        }
        return nums;
    }
};