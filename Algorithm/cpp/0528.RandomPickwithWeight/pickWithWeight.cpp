class Solution {
public:
    Solution(vector<int>& w) : pre_sum(std::move(w)){
        partial_sum(pre_sum.begin(), pre_sum.end(), pre_sum.begin());
    }

    int pickIndex() {
        int pos = (rand() % pre_sum.back()) + 1;
        return lower_bound(pre_sum.begin(), pre_sum.end(), pos) - pre_sum.begin();
    }
private:
    vector<int> pre_sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */