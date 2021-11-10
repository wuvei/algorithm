#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (!nums.size()) return vector<int>();
        int left = 0, right = nums.size() - 1;
        vector<int> res(nums);
        while (left < right) {
            while (left < right && nums[left] % 2) left++;
            while (left < right && nums[right] % 2 == 0) right--;
            if (left < right) {
                res[right] = nums[left];
                res[left] = nums[right];
                left++;
                right--;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums({1,2,3,4});
    Solution s;
    vector<int> res = s.exchange(nums);
    for (int e: res)
        cout << e << " ";
    cout << endl;
    return 0;
}