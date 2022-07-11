// recursion
class Solution {
public:
    void add (int n) {
        if (cache.find(n) != cache.end())
            return;
        for (int i = 0; i < n; ++i) {
            add(i);
            add(n - 1 - i);
            for (auto &s1: cache[i]) {
                for (auto &s2: cache[n - 1 - i]) {
                    cache[n].push_back("(" + s1 + ")" + s2);
                }
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        cache.clear();
        cache[0] = {""};
        cache[1] = {"()"};
        add(n);
        return cache[n];
    }
private:
    unordered_map<int, vector<string> > cache;
};

// dfs
class Solution {
public:
    void dfs (int idx, int l, int r) {
        if (!l && !r) {
            ans.push_back(single);
            return;
        }
        if (l) {
            single[idx] = '(';
            dfs(idx + 1, l - 1, r);
        }
        if (r && r > l) {
            single[idx] = ')';
            dfs(idx + 1, l, r - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        single.resize(2 * n);
        dfs(0, n, n);
        return ans;
    }
private:
    string single;
    vector<string> ans;
};