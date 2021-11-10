class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size(), ret = 0;
        vector<int> candy(len, 1);
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
        }
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) candy[i] = max(candy[i], candy[i + 1] + 1);
            ret += candy[i];
        }
        ret += candy[len - 1];
        return ret;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1;
        int inc = 1, dec = 0, last = 1;
        for(int i = 1; i < ratings.size(); ++i)
        {
            if(ratings[i] >= ratings[i - 1])
            {
                last = ratings[i] == ratings[i - 1]? 1 : last + 1;
                ans += last;
                inc = last;
                dec = 0;
            }
            else
            {
                ++dec;
                if (dec == inc) ++dec;
                ans += dec;
                last = 1;
            }
        }
        return ans;
    }
};
// 作者：Xiaohu9527
// 链接：https://leetcode-cn.com/problems/candy/solution/ctan-xin-suan-fa-yi-ci-bian-li-chao-ji-x-cvgb/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。