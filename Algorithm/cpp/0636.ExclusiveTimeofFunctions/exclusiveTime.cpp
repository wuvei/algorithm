class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st;
        vector<int> res(n, 0);
        for (auto& log : logs) {
            char type[10];
            int idx, timestamp;
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);
            if (type[0] == 's') {
                if (!st.empty()) {
                    res[st.top().first] += timestamp - st.top().second;
                    st.top().second = timestamp;
                }
                st.emplace(idx, timestamp);
            } else {
                auto t = st.top();
                st.pop();
                res[t.first] += timestamp - t.second + 1;
                if (!st.empty()) {
                    st.top().second = timestamp + 1;
                }
            }
        }
        return res;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/exclusive-time-of-functions/solution/han-shu-de-du-zhan-shi-jian-by-leetcode-d54e2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。