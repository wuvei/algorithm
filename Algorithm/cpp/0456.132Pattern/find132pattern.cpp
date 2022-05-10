class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int right = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < right) return true;
            while (!st.empty() && st.top() < nums[i]) {
                int temp = st.top();
                if (right < temp) right = temp;
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};