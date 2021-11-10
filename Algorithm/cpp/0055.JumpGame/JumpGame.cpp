#include<iostream>
#include<vector>

using namespace std;
/*
    Greedy: Time Complicity: O(n), Space Complicity: O(1)
    Always calculate the farest index the current index
    could jump to.

*/
class Solution{
public:
    bool canJump(vector<int>& nums) {
        int farest = 0, length = nums.size();
        bool canReach = false;
        for(int i = 0; i <= farest && i < length; i++){
            farest = max(i + nums[i], farest);
            if(farest > length - 2){
                canReach = true;
                break;
            }
        }
        return canReach;
    }
};

int main(){
    int input[] = {0};//{3,2,1,0,4};
    vector<int> nums(input, input + 1);
    Solution solution;
    cout << solution.canJump(nums) << endl;
    return 0;
}