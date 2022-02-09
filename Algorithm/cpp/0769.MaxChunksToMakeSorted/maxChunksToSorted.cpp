class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0, curMax = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (curMax < arr[i]) {
                curMax = arr[i];
            }
            if (curMax == i)
                cnt++;
        }
        return cnt;
    }
};