class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long l = nums1[0] + nums2[0], r = nums1.back() + nums2.back();
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (smallerOrEqual(mid, nums1, nums2) < k) l = mid + 1;
            else r = mid;
        }
        vector<vector<int> > ans, tail;
        for (int e: nums1) {
            for (int e2: nums2) {
                if (e + e2 > l) break;
                else if (e + e2 == l)
                    tail.push_back({e, e2});
                else
                    ans.push_back({e, e2});
            }
        }
        // if (ans.size() < k) {
        //     int temp = std::min(tail.size(), k - ans.size());
        //     ans.reserve(ans.size() + distance(tail.begin(), tail.begin() + temp));
        //     ans.insert(ans.end(), tail.begin(), tail.begin() + temp);
        // }
        if (ans.size() < k) {
            int temp = std::min(tail.size(), k - ans.size());
            for (int i = 0; i < temp; i++) ans.push_back(tail[i]);
        }
        return ans;
    }
                
    long smallerOrEqual(int val, vector<int>& nums1, vector<int>& nums2)
    {
        long ret = 0;
        for (int i = 0, j = nums2.size() - 1; i < nums1.size(); i++)
        {
            while (j >= 0 && nums1[i]+nums2[j] > val)
                j--;
            ret += j+1;
        }
        return ret;
    }
};