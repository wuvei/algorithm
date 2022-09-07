class Solution {
private:
    vector<int> ans;
    string s;
    int n, k;
public:
    void dfs(int idx, unsigned char c) {
        s[idx] = c;
        if (idx == n - 1) {
            ans.push_back(stoi(s));
            return;
        }
        if (std::isdigit(c + k)) {
            dfs(idx + 1, c + k);
        }
        if (k && std::isdigit(c - k)) {
            dfs(idx + 1, c - k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        ans.clear();
        this->n = n;
        this->k = k;
        for (unsigned char c = '1'; c <= '9'; ++c) {
            dfs (0, c);
        }
        return ans;
    }
};