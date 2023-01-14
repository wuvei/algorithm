class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, int> m;
        for (int i = 0; i < knowledge.size(); ++i)
            m[knowledge[i][0]] = i;
        string ans, t = "";
        ans.reserve(s.size());
        int state = 0;
        for (char c: s) {
            if (c == '(') state = 1;
            else if (c == ')') {
                if (m.count(t)) ans += knowledge[m[t]][1];
                else ans += "?";
                t = "";
                state = 0;
            }
            else if (state) t += c;
            else ans += c;
        }
        return ans;
    }
};