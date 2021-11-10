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
            // for(vector<int>::iterator it = start; it != end; it++ ){
            //     cout << *it << " ";
            // }
            // cout << "\n";
            result.push_back(nums);
        }while(next_permutation(start, end));

        return result;
    }
};

int main(){
    Solution s;
    int tmp[] = {0,1,-1};
    vector<int> ilist(tmp, tmp + 3);
    s.permute(ilist);
    return 0;
}