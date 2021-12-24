class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), less<int>());
        this -> curSum = 0;
        this -> target = target;
        result.clear();
        backtracking(candidates, 0);
        return result;
    }

private:
    void backtracking(vector<int>& candidates, int start) {
        if (curSum > target) {
            return; // 剪枝
        }

        if (curSum == target) {
            result.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if ((i > start) && (candidates[i] == candidates[i - 1])) {
                continue; // skip
            }
            curSum += candidates[i];
            cur.push_back(candidates[i]);
            backtracking(candidates, i + 1);
            curSum -= candidates[i];
            cur.pop_back();
        }
    }

private:
    int curSum, target;
    vector<vector<int>> result;
    vector<int> cur;
};

// From https://leetcode-cn.com/problems/combination-sum-ii/solution/chui-su-jian-zhi-qiu-zi-ji-shu-tiao-guo-2gqto/
