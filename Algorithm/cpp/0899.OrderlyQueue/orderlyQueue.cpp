class Solution {
public:
    string orderlyQueue(string s, int _k) {
        if (_k == 1) {
            int i = 0, j = 1, k = 0, n = s.size();
            while (i < n && j < n && k < n) {
                char a = s[(i + k) % n], b = s[(j + k) % n];
                if (a == b) k++;
                else {
                    if (a > b) i += k + 1;
                    else j += k + 1;
                    if (i == j) ++i;
                    k = 0;
                }
            }
            i = min(i, j);
            return s.substr(i) + s.substr(0, i);
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};

// 作者：宫水三叶
// 链接：https://leetcode.cn/problems/orderly-queue/solutions/1718120/by-ac_oier-443m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。