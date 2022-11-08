class Solution {
public:
    vector<string> getStrs(string s){
       vector<string> list;
       for (int i = 1; i <= s.size(); ++i) {
            string left = s.substr(0, i), right = s.substr(i, s.size() - i);
            if((left.size() > 1 && left[0] == '0') || (right.size() > 0 && right[right.size() - 1] == '0'))
               continue;
            if(right.size() == 0) 
                list.push_back(left);
            else
                list.push_back(left + "." + right);
       } 
       return std::move(list);
    }

    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1, s.size() - 2);
        int n = s.size();
        for(int i = 1; i < n; ++i){
            for(string &x: getStrs(s.substr(0, i)))
                for(string &y: getStrs(s.substr(i, n - i)))
                    ans.push_back("(" + x + ", " + y + ")");
        }
        return ans;
    }
};