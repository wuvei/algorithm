class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt, first;
        int degree = 0, len = 0;
        for(int i = 0; i < nums.size(); ++i){
            int e = nums[i];
            cnt[e]++;
            if(!first.count(e)) first[e] = i;
            if(cnt[e] > degree || (cnt[e] == degree && i - first[e] + 1 < len)) {
                degree = cnt[e];
                len = i - first[e] + 1;
            }
        }
        return len;
    }
};


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m, left, right;
        int degree = 0, ans = nums.size();
        for (int i = 0; i < ans; i++) {
            int e = nums[i];
            if (m.find(e) == m.end())
                left[e] = i;
            right[e] = i;
            m[e]++;
            degree = std::max(degree, m[e]);
        }
        for (auto &it: m) {
            if (it.second == degree)
                ans = std::min(ans, right[it.first] - left[it.first] + 1);
        }
        return ans;
    }
};