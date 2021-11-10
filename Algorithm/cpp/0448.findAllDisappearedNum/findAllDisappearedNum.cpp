#include<iostream>
#include<vector>

using namespace std;
/*
    For each number i in nums,
    we mark the number that i points as negative.
    Then we filter the list, get all the indexes
    who points to a positive number.
    Since those indexes are not visited.
*/
class Solution{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index, length = nums.size();
        for(int i = 0; i < length; i++){
            index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }
        vector<int> result;
        for(int i = 0; i < length; i++)
            if(nums[i] > 0)
                result.push_back(i + 1);
        return result;
    }
};
int main(){
    int temp[] = {4,3,2,7,8,2,3,1};
    vector<int> test(temp, temp + sizeof(temp)/sizeof(*temp));
    Solution a;
    vector<int> re = a.findDisappearedNumbers(test);
    for(int i = 0; i < re.size(); i++)
        cout << re[i] << " ";
    cout << endl;
    return 0;
}