#include<iostream>
#include<queue>

using namespace std;
/*
    Greedy Algorithm
    Always calculate the farest position that we could reach
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0, pre = 0, step = 0, goal = nums.size() - 1, i = 0;
        while(cur < goal){
            step++;
            pre = cur;
            for(; i <= pre; i++){
                cur = max(cur, i + nums[i]);
            }
        }
        return step;
    }
};

int main()
{
    Solution s;
    int tmp[] = {2,3,1,1,4};
    // int tmp[] = {1,1,1,1,4};
    vector<int> dat(tmp, tmp + 5);
    cout << s.jump(dat)<< endl;
    return 0;
}