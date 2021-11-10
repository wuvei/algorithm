class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> inStack(26, false);
        for (char c: s) count[c - 'a']++;
        string ans;
        for (char c: s) {
            count[c - 'a']--;
            if (inStack[c - 'a']) continue;
            while(ans.size() && count[ans.back() - 'a'] && ans.back() > c) {
                inStack[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            inStack[c - 'a']= true;
            ans.push_back(c);
        }
        return ans;
    }
};