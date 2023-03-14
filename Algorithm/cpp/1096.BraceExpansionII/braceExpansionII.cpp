class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        return vector<string>(s.begin(), s.end());
    }

private:
    set<string> s;

    void dfs(string exp) {
        int j = exp.find_first_of('}');
        if (j == string::npos) {
            s.insert(exp);
            return;
        }
        int i = exp.rfind('{', j);
        string a = exp.substr(0, i);
        string c = exp.substr(j + 1);
        stringstream ss(exp.substr(i + 1, j - i - 1));
        string b;
        while (getline(ss, b, ',')) {
            dfs(a + b + c);
        }
    }
};

// 作者：ylb
// 链接：https://leetcode.cn/problems/brace-expansion-ii/solutions/2152366/python3javacgotypescript-yi-ti-yi-jie-di-gs64/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    vector<string> multiply(vector<string>& a, vector<string>& b){
        if (a.empty()) return b;
        if (b.empty()) return a;
        vector<string> ans;
        for(auto &i : a){
            for(auto &j : b) 
                ans.push_back(i + j);
        }
        return std::move(ans);
    }
    
    vector<string> braceExpansionII(string expression) {
        vector<string>  res, curr;
        stack<vector<string>> st;
        for(char x : expression){
            if(x >= 'a' and x <= 'z'){
                if (curr.size()) for (auto &i : curr) i += x;
                else curr.push_back(string(1, x));
            }
            else if(x == '{'){
                st.push(res);
                st.push(curr);
                res.clear();
                curr.clear();
            }
            else if(x == '}'){
                vector<string> preCurr = st.top(); st.pop();
                vector<string> preRes = st.top(); st.pop();
                for(auto &i : curr) res.push_back(i);
                curr = multiply(preCurr, res);
                res = preRes;
            }
            else if(x == ','){
                for(auto &i: curr) res.push_back(i);
                curr.clear();
            }
        }
        for(auto &i : curr) res.push_back(i);
        sort(res.begin(), res.end());
        return vector<string>(res.begin(), unique(res.begin(), res.end()));
    }
};