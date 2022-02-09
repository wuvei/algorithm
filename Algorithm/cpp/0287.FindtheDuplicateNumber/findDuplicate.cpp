// Slow-Fast Pointers
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


// Binary Search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int num : nums) {
                if (num <= mid)
                    cnt += 1;
            }
            if (cnt > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }