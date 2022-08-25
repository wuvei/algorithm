// https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/2446873/C%2B%2B-Easy-Solution-or-Map-or-W-Explanation

// Traverse the array nums and record the frequencies of the elements in a map counts.

// Then traverse it again, and at each number i, check for the following conditions :

// If a consecutive subsequence ends with the previous number (i.e; i-1), then we append i to that sequence.
// Else we check if we can make a new consecutive subsequence starting from i and having atleast 3 numbers in it.
// If we can do neither of these, we return false.
// If we traversed the whole array successfully, that means we could split the array into 1 or more consecutive subsequences of size >= 3, So we return true.

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> tails, counts;
        
        for (auto &num: nums) ++counts[num];
        
        for (auto &i: nums) {
            if (!counts[i]) continue;
            
            if (tails[i - 1] > 0) {
                --counts[i];
                --tails[i-1];
                ++tails[i];
            } 
            else if (counts[i + 1] > 0 && counts[i + 2] > 0) {
                --counts[i];
                --counts[i+1];
                --counts[i+2];
                ++tails[i+2];
            } 
            else return false;
        }
        return true;
    }
};


// map + heap
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>,greater<int>>> mp;
        for (auto& x : nums) {
            if (mp.find(x) == mp.end()) {
                mp[x] = priority_queue<int, vector<int>,greater<int>>();
            }
            if (mp.find(x - 1) != mp.end()) {
                int prevLength = mp[x - 1].top();
                mp[x - 1].pop();
                if (mp[x - 1].empty()) {
                    mp.erase(x - 1);
                }
                mp[x].push(prevLength + 1);
            } else {
                mp[x].push(1);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            priority_queue<int, vector<int>,greater<int>> queue = it->second;
            if (queue.top() < 3) {
                return false;
            }
        }
        return true;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/split-array-into-consecutive-subsequences/solution/fen-ge-shu-zu-wei-lian-xu-zi-xu-lie-by-l-lbs5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int i = 0;

        while (i < n) {
            int start = i;
            int x = nums[i];
            while (i < n && nums[i] == x) {
                i++;
            }
            int cnt = i - start;

            if (start > 0 && x != nums[start - 1] + 1) {
                if (dp1 + dp2 > 0) {
                    return false;
                } else {
                    dp1 = cnt;
                    dp2 = dp3 = 0;
                }
            } else {
                if (dp1 + dp2 > cnt) return false;
                int left = cnt - dp1 - dp2;
                int keep = min(dp3, left);
                dp3 = keep + dp2; // 这里要注意赋值的顺序
                dp2 = dp1;
                dp1 = left - keep;
            }
        }
        return dp1 == 0 && dp2 == 0;
    }
};

// 作者：Arsenal-591
// 链接：https://leetcode.cn/problems/split-array-into-consecutive-subsequences/solution/tan-xin-o1-kong-jian-fu-za-du-de-zui-you-jie-fa-by/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。