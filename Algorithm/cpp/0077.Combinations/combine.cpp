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


class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    int n, k;
    void backtracking(int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // 处理节点 
            backtracking(i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        this -> n = n;
        this -> k = k;
        backtracking(1);
        return result;
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/combinations/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-0uql/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this -> n = n;
        this -> k = k;
        ans.clear();
        comb.clear();
        backtracking(1);
        return ans;
    }

    void backtracking(int cur) {
        if (idx > k) {
            ans.push_back(comb);
            return;
        }
        int x = comb.size() + 1;
        for (int i = cur; i <= n - k + x; i++) {
            comb.push_back(i);
            backtracking(i + 1);
            comb.pop_back();
        }
    }
private:
    vector<vector<int> > ans;
    vector<int> comb;
    int n, k;
};