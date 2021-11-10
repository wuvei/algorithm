class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ans.resize(numCourses, 0);
        visit.resize(numCourses, 0);
        child.resize(numCourses, vector<int>());
        idx = numCourses - 1;
        for (auto v: prerequisites)
            child[v[1]].push_back(v[0]);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return vector<int>();
        }
        return ans;        
    }
    
    bool dfs(int n) {
        if (visit[n] == 1) return false;
        else if (visit[n] == -1) return true;
        visit[n] = 1;
        
        for (int e: child[n]) {
            if (!dfs(e)) return false;
        }
        visit[n] = -1;
        ans[idx--] = n;
        return true;
    }
private:
    vector<int> ans, visit;
    vector<vector<int> > child;
    int idx;
};