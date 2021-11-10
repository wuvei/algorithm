class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int half = nums.size()/2;
        vector<vector<int> > lsum = getSum(nums, 0, half - 1), rsum = getSum(nums, half, nums.size() - 1);
        int total = lsum[half][0] + rsum[half][0], half_total = total / 2, ans = INT_MAX;
        for (int i = 0; i <= half; i++) {
            for (int j = 0; j < lsum[i].size(); j++) {
                vector<int> &temp = rsum[half - i];
                auto it = lower_bound(temp.begin(), temp.end(), half_total - lsum[i][j]);
                if (it == temp.begin()) {
                    ans = min(ans, abs(total - 2*(lsum[i][j] + temp[0])));
                } else if (it == temp.end()) {
                    ans = min(ans, abs(total - 2*(lsum[i][j] + temp.back())));
                } else {
                    ans = min(ans, abs(total - 2*(lsum[i][j] + *it)));
                    ans = min(ans, abs(total - 2*(lsum[i][j] + *(it - 1))));
                }
            }
        }        
        return ans;
    }
    vector<vector<int> > getSum(vector<int>& nums, int l, int r) {
        vector<vector<int> > sum(r - l + 2, vector<int>());
        sort(nums.begin()  + l, nums.begin() + r + 1);
        sum[0].push_back(0);
        int cnt = 1, row_prev;
        for (int idx = l; idx <= r; idx++) {
            int x = nums[idx];
            vector<int> prev_row = sum[0];
            for (int i = 0; i < cnt; i++) {
                int n = prev_row.size(), m = sum[i + 1].size();
                vector<int> v;
                for (int j = 0, k = 0; j < n || k < m;) {
                    if (j == n) v.push_back(sum[i + 1][k++]);
                    else if (k == m) v.push_back(prev_row[j++] + x);
                    else if (sum[i + 1][k] < prev_row[j] + x) v.push_back(sum[i + 1][k++]);
                    else v.push_back(prev_row[j++] + x);
                }
                prev_row = sum[i + 1];
                sum[i + 1] = v;
            }
            cnt++;
        }
        return sum;
    }
};