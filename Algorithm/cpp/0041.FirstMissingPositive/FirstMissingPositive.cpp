#include<iostream>
#include<vector>

using namespace std;
/*
    We could leverage the solution of 448.
    Find All Disappeared Numbers. If there were
    N numbers in the vector, the result must be
    1 ~ N + 1. Therefore we could operate on
    the original array. We marked number not in
    [1, N] as N + 1, a number that is not in
    this range.
    For each number i in nums,
    we mark the number that i points as negative.
    Then we filter the list, get the first index
    who points to a positive number.
    Since that index is not visited and is the
    first missing positive number.
*/
class Solution{
public:
    int findDisappearedNumbers(vector<int>& nums) {
        int index, length = nums.size();
        for(int i = 0; i < length; i++){
            if(nums[i] < 1 || nums[i] > length)
                nums[i] = length + 1;
        }
        for(int i = 0; i < length; i++){
            index = abs(nums[i]) - 1;
            if(index >=0 && index < length)
                nums[index] = -abs(nums[index]);
        }
        for(int i = 0; i < length; i++)
            if(nums[i] >= 0)
                return i + 1;
        return length + 1;
    }
};
int main(){
    int temp[] = {0,1,2};
    vector<int> test(temp, temp + sizeof(temp)/sizeof(*temp));
    Solution a;
    int re = a.findDisappearedNumbers(test);
    cout << re << endl;
    return 0;
}