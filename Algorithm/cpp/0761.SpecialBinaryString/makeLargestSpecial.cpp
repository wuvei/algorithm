class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() == 2) return "10";
        vector<string> v;
        for(int i = 0, cur = 0, last = 0; i < s.size(); ++i) {
            (s[i] == '1')? cur++ : cur--;
            if(cur == 0) {
                v.push_back("1");
                v.back() += makeLargestSpecial(s.substr(last + 1, i - last - 1)) + '0';
                last = i + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        
        return accumulate(v.begin(), v.end(), ""s);
    }
};