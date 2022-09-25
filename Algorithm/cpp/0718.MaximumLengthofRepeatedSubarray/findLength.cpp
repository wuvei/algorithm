class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, len1 = nums1.size(), len2 = nums2.size(), upleft, temp;
        vector <int> dp(len2 + 1, 0);
        for (int i = 1; i <= len1; i++) {
            upleft = dp[0];
            for (int j = 1; j <= len2; j++) {
                temp = dp[j];
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = upleft + 1;
                    ans = std::max(ans, dp[j]);
                }
                else dp[j] = 0;
                upleft = temp;
            }
        }
        
        return ans;
    }
};

// two pointers
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        return nums1.size() <= nums2.size() ? helper(nums1, nums2) : helper(nums2, nums1);
    }
    //窗口滑动的重叠过程可以分为三个过程：
    //1、下面子串进入，开始重叠的过程
    //2、上下两子串完全重叠，中间过程
    //3、下面的子串开始离开，重叠区域减少，离开过程
    int helper(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size(), ret = 0;
        //进入时候的处理
        for(int i = 1; i <= len1; ++i) {
            ret = max(ret, maxlen(nums1, 0, nums2, len2 - i, i));
        }
        //中间过程的处理
        for(int i = len2; i - len1 >= 0; --i) {
            ret = max(ret, maxlen(nums1, 0, nums2, i - len1, len1));
        }
        //出去时的处理
        for(int i = len1; i > 0; --i) {
            ret = max(ret, maxlen(nums1, len1 - i, nums2, 0, i));
        }
        return ret;
    }
    int maxlen(vector<int> &nums1, int idx1, vector<int> &nums2, int idx2, int len) {
        int ret = 0, count = 0;
        for(int i = 0; i < len; ++i) {
            if(nums1[idx1 + i] == nums2[idx2 + i]) {
                ++count;
            }
            else if(count > 0) {
                ret = max(ret, count);
                count = 0;
            }
        }
        return max(ret, count);
    }
};