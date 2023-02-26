// O(nlog(a_max)logn)
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mi = 1e9 + 5;
        for (int &e: nums) {
            if (e & 1) e <<= 1;
            pq.push(e);
            mi = std::min(mi, e);
        }
        int ans = pq.top() - mi;
        while ((pq.top() & 1) == 0) {
            int e = pq.top();
            pq.pop();
            ans = std::min(ans, e - mi);
            e >>= 1;
            mi = std::min(mi, e);
            pq.push(e);
        }
        return std::min(pq.top() - mi, ans);
    }
};

// O(nlogn)
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int p_max = 1;
        for(int a : nums) p_max = max(p_max, a >> (__builtin_ctz(a)));
        vector<int> upper;
        int min = p_max;
        for(int a : nums){
            if(a & 1) a <<= 1;
            if(a >= p_max){
                a >>= __builtin_clz(p_max) - __builtin_clz(a);
                if(a < p_max) a <<= 1;
                upper.push_back(a);
            }
            min = std::min(min, a);
        }
        sort(upper.begin(), upper.end());
        int ans = upper.back() - min;
        for(int i = upper.size() - 1; upper[i] > p_max; i -= 1){
            min = std::min(min, upper[i] >> 1);
            ans = std::min(ans, upper[i - 1] - min);
        }
        return ans;
    }
};

// 作者：何逊
// 链接：https://leetcode.cn/problems/minimize-deviation-in-array/solutions/503280/yi-chong-fu-za-du-geng-di-de-zuo-fa-by-heltion-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。