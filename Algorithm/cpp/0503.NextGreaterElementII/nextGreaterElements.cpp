class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=0;i<n*2;i++) {
            while(!st.empty() and nums[st.top()] < nums[i%n]) {
                res[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return res;
    }
};