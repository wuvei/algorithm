class Solution {
public:
    void dfs(int start, int ind, int left) {
        if (ind == v.size()) {
            if (left == 0) ans.push_back(v);
            return;
        }
        for (int i = start; i <= 10 - v.size() + ind; ++i) {
            v[ind] = i;
            if (left >= i)
                dfs(i + 1, ind + 1, left - i);
        } 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > 45 || n < k * (k + 1) / 2) return ans;
        v.resize(k);
        dfs(1, 0, n);
        return ans;
        
    }
private:
    vector<vector<int> > ans;
    vector<int> v;
};