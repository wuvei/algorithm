class NumArray {
public:
    inline int lowbit(int x) {
        return x & (-x);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        _nums = nums;
        tree.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            add(i, nums[i - 1]);
    }

    void update(int index, int val) {
        int delta = val - _nums[index];
        _nums[index] = val;
        add(index + 1, delta);
    }

    void add(int x, int delta) {
        for (int i = x; i <= n; i += lowbit(i)) tree[i] += delta;
    }

    int preSum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowbit(i);
        }
        return sum;
    }
    int sumRange(int left, int right) {
        return preSum(right + 1) - preSum(left);
    }
private :
    vector<int> tree, _nums;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */