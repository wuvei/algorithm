#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// http://www.cplusplus.com/reference/algorithm/next_permutation/

class Solution{

public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector<int>::iterator start = nums.begin();
        vector<int>::iterator end = nums.end();
        sort(start, end);
        vector< vector<int> > result;
        do{
            result.push_back(nums);
        }while(next_permutation(start, end));

        return result;
    }
};

// backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }
    void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans) {
        if (level == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); i++) {
            swap(nums[i], nums[level]); // 修改当前节点状态
            backtracking(nums, level+1, ans); // 递归子节点
            swap(nums[i], nums[level]); // 回改当前节点状态
        }

    }
};


int main(){
    Solution s;
    int tmp[] = {0,1,-1};
    vector<int> ilist(tmp, tmp + 3);
    s.permute(ilist);
    return 0;
}