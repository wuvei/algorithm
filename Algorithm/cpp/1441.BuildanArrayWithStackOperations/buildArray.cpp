class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        ans.reserve(n << 1);
        int j=0;
        for (int i=1; i <= n && j< target.size(); ++i) {
            if(target[j]==i){
                ans.push_back("Push");
                ++j;
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};