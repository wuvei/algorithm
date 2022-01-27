class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = nums.size() / 2;
        while (l < r) {
            int i = l, j = r, pivot = rand() % (r - l) + l;
            swap(nums[i], nums[pivot]);
            pivot = nums[i];
            while (i < j) {
                while (i < j && nums[j] >= pivot) j--;
                while (i < j && nums[i] <= pivot) i++;
                if (i < j) swap(nums[i], nums[j]);
            }
            nums[l] = nums[i];
            nums[i] = pivot;
            if (i == mid) break;
            else if (i > mid) r = i - 1;
            else l = i + 1;
        }
        int ans = 0;
        mid = nums[mid];
        for (int e: nums) {
            ans += e > mid? e - mid: mid - e;
        }
        return ans;
    }
};


class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int mid = static_cast<int>(nums.size()) / 2, ans = 0;
        nth_element(begin(nums), next(begin(nums), mid), end(nums));
        for_each(begin(nums), end(nums), [&](int num) { ans += abs(num - nums[mid]); });
        return ans;
    }
};

// 作者：kevinchen147
// 链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/solution/czhong-wei-shu-jian-dan-zheng-ming-by-ke-a2v9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。