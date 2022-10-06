class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.length() != s2.length()) {
            return false;
        }
        int n = s1.length(), i = 0, j = 0;
        while(i<n)
            (s1[i++] == s2[j++])? : j = 0;
        i = 0;
        while(j<n)
            (s1[i++] == s2[j++])? : n =- 1;
        return (j == n) ? true : false;
    }
};

// 作者：er-yue-xie
// 链接：https://leetcode.cn/problems/string-rotation-lcci/solution/by-er-yue-xie-636q/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。