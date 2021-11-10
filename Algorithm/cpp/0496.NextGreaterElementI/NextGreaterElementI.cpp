class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        unordered_map<int, int> m;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] >= s.top()) s.pop();
            m[nums2[i]] = s.empty() ? -1: s.top();
            s.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = m[nums1[i]];
        }
        return res;
    }

    // 4ms
    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        map<int, int> m;
        vector<int> v;
        for(int i = nums2.size()-1; i >= 0; i--){
            if(s.empty()){
                s.push(nums2[i]);
                m[nums2[i]] = -1;
            }else if(s.top() > nums2[i] && !s.empty()){
                m[nums2[i]] = s.top();
                s.push(nums2[i]);
            }else if(!s.empty()){
                while(!s.empty() && s.top() < nums2[i]){
                    s.pop();
                }
                if(s.empty()){
                    m[nums2[i]] = -1;
                    s.push(nums2[i]);
                }else{
                    m[nums2[i]] = s.top();
                    s.push(nums2[i]);
                }
            }
        }
        
        for(int z : nums1){
            auto it = m.find(z); 
            if(it == m.end()){
                v.push_back(-1);
            }else{
                v.push_back(it->second);
            }
        }
        return v;
    }
};