class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), left = 0, len = 0;
        for(int i = 0; i < n; i ++) {
            if(i == n - 1 || chars[i] != chars[i + 1]) {
                chars[len++] = chars[i];
                int nums = i - left + 1;
                if(nums > 1) {
                    for(char c : to_string(nums)) {
                        chars[len++] = c;
                    }
                }
                left = i + 1;
            }
        }
        return len;
    }
};

// 作者：HERODing
// 链接：https://leetcode.cn/problems/string-compression/solutions/948676/cshuang-zhi-zhen-xiang-jie-by-heroding-tb7x/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。