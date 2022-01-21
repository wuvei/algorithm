class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, curr = 1; //dp[-1] = dp[0] = 1
        for (int i = 1; i < s.size(); i++) {
            int tmp = curr;
            if (s[i] == '0')
                if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
                else return 0;
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                curr = curr + pre;
            pre = tmp;
        }
        return curr;
    }
};

// https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/

class Solution {
public:
    int numDecodings(string s) {
        int dec_from_idx_plus_one = 1;
        int dec_from_idx_plus_two = 1;
        int dec_count = 0;

        if (s[s.size() - 1] == '0')
            dec_from_idx_plus_one = 0;
        else dec_count = 1;

        for(int idx = s.size() - 2; idx >= 0; --idx){
            if(s[idx] == '0')
                dec_count = 0;
            else {
                dec_count = dec_from_idx_plus_one;
                if(s[idx] == '1' or (s[idx] == '2' and s[idx+1] <= '6'))
                    dec_count += dec_from_idx_plus_two;
            }

            dec_from_idx_plus_two = dec_from_idx_plus_one;
            dec_from_idx_plus_one = dec_count;
        }

        return dec_count;
    }
};

// https://leetcode.com/problems/decode-ways/discuss/1641791/Medium-Decode-ways-O(n)-time-O(1)-space-Iterative-Beats-100-time