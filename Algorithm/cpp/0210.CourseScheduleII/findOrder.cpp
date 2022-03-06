// DFS
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

// BFS
class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> indeg;
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& e: prerequisites) {
            edges[e[1]].push_back(e[0]);
            ++indeg[e[0]];
        }

        queue<int> q;
        // 将所有入度为 0 的节点放入队列中
        for (int i = 0; i < numCourses; ++i)
            if (!indeg[i]) q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for (int v: edges[u]) {
                --indeg[v];
                if (!indeg[v]) q.push(v);
            }
        }

        if (result.size() != numCourses) return {};
        return result;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/course-schedule-ii/solution/ke-cheng-biao-ii-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。