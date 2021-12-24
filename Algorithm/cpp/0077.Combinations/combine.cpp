class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this -> n = n;
        this -> k = k;
        ans.clear();
        comb.clear();
        backtracking(1, 1);
        return ans;
    }

    void backtracking(int idx, int cur) {
        if (idx > k) {
            ans.push_back(comb);
            return;
        }
        for (int i = cur; i <= n - k + idx; i++) {
            comb.push_back(i);
            backtracking(idx + 1, i + 1);
            comb.pop_back();
        }
    }
private:
    vector<vector<int> > ans;
    vector<int> comb;
    int n, k;
};