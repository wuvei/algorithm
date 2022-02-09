// Hierholzer算法
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        if (tickets.empty()) return ans;
        unordered_map<string, multiset<string> > m;
        for (auto &tick: tickets)
            m[tick[0]].insert(tick[1]);
        stack<string> s;
        s.push("JFK");
        while (!s.empty()) {
            string next = s.top();
            if (m[next].empty()) {
                ans.push_back(next);
                s.pop();
            } else {
                s.push(*m[next].begin());
                m[next].erase(m[next].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
private:
// unordered_map<出发城市, map<到达城市, 航班次数>> targets
unordered_map<string, map<string, int>> targets;
bool backtracking(int ticketNum, vector<string>& result) {
    if (result.size() == ticketNum + 1) {
        return true;
    }
    for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
        if (target.second > 0 ) { // 使用int字段来记录到达城市是否使用过了
            result.push_back(target.first);
            target.second--;
            if (backtracking(ticketNum, result)) return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
}
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/reconstruct-itinerary/solution/332-zhong-xin-an-pai-xing-cheng-hui-su-fa-shen-sou/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。