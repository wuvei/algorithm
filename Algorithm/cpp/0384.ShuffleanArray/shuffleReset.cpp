class Solution {
public:
    Solution(vector<int>& nums): origin(std::move(nums)) {
        shuf = origin;
    }

    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {
        for (int i = origin.size() - 1; i >= 0; --i)
            swap(shuf[i], shuf[rand() % (i + 1)]);
        return shuf;
    }
private:
    vector<int> origin, shuf;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */