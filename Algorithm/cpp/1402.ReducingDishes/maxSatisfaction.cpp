class Solution {
public:
       int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int ans = 0, sum = 0;
        for (int i = 0; i < satisfaction.size(); ++i) {
            sum += satisfaction[i];
            if (sum < 0) break;
            ans += sum;
        }
        return ans;
    }

// 作者：Ikaruga
// 链接：https://leetcode.cn/problems/reducing-dishes/solutions/187275/reducing-dishes-by-ikaruga/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
};