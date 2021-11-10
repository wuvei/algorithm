class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        child.resize(numCourses, unordered_set<int>());
        isReachable.resize(numCourses, vector<int>(numCourses, 0));
        for (auto v: prerequisites) child[v[0]].insert(v[1]);
        vector<bool> ans;
        for (auto v: queries) {
            ans.push_back(dfs(v[0], v[1]));
        }
        return ans;
    }
    bool dfs(int a, int b) {
        if (isReachable[a][b] != 0) return (isReachable[a][b] == 1);
        if (child[a].count(b)) return isReachable[a][b] = 1;
        int res = -1;
        for (int ch: child[a]) {
            if (dfs(ch, b)) {
                res = 1;
                break;
            } 
        }
        return (isReachable[a][b] = res) == 1;
    }
private:
    vector<vector<int> > isReachable;
    vector<unordered_set<int> > child;
};