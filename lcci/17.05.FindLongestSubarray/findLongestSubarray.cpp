class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int start = 0, len = 0, pre = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < array.size(); ++i) {
            if (std::isdigit(array[i][0])) --pre;
            else ++pre;
            if (!m.count(pre)) m[pre] = i;
            if (len < i - m[pre]) {
                len = i - m[pre];
                start = m[pre] + 1;
            }
        }
        return vector<string>(array.begin() + start, array.begin() + start + len);
    }
};