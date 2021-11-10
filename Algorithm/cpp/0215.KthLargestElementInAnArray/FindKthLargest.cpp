class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int orig_l = l;
        while (l < r) {
            while (l < r && nums[r] <= nums[orig_l]) r--;
            while (l < r && nums[l] >= nums[orig_l]) l++;
            if (l < r) swap(nums[l], nums[r]);
        }
        swap(nums[orig_l], nums[l]);
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int l = 0, r = nums.size() - 1;
        while(true) {
            int pivot = rand() % (r - l + 1) + l;
            swap(nums[pivot], nums[l]);
            int index = partition(nums, l, r);
            if (index == k - 1) return nums[index];
            else if (index > k - 1) r = index - 1;
            else l = index + 1;
        }
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 小顶堆
        priority_queue<int, vector<int>, greater<int>> pq;
        int sz = nums.size();
        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }
        for (int i = k; i < sz; ++i) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

// 作者：moreality
// 链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/215-shu-zu-zhong-de-di-kge-zui-da-yuan-s-h4aj/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 手撕小顶堆
        vector<int> heap(k);
        for (int i = 0; i < k; ++i) {
            int j = i;
            while(j > 0) {
                int parent = (j - 1) / 2;
                if (heap[parent] > nums[i]) {
                    heap[j] = heap[parent];
                    j = parent;
                }
                else break;
            }
            heap[j] = nums[i];
        }
        int sz = nums.size();
        for (int i = k; i < sz; ++i) {
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                int j = 0;
                while(1) {
                    int leftc = 2 * j + 1, rightc = 2 * j + 2;
                    int smallest = j;
                    if (leftc < k && heap[smallest] > heap[leftc]) smallest = leftc;
                    if (rightc < k && heap[smallest] > heap[rightc]) smallest = rightc;
                    if (smallest == j) break;
                    else {
                        swap(heap[j], heap[smallest]);
                        j = smallest;
                    }
                }
            }
        }
        return heap[0];
    }
};