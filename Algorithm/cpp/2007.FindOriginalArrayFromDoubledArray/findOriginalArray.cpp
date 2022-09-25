class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() & 1) {
            return {};
        }
        map<int, int> m;
        for (int e: changed) {
            ++m[e];
        }
        vector<int> ans;
        if (m[0]) {
            if (m[0] & 1) {
                return {};
            }
            m[0] >>= 1;
            while (--m[0]) {
                ans.push_back(0);
            }
            ans.push_back(0);
        }
        for (auto &[k, v] : m) {
            if (!v) {
                continue;
            }
            int e = k << 1;
            if (m[e] < v) {
                return {};
            }
            for (int i = 0; i < v; ++i) {
                ans.push_back(k);
            }
            m[e] -= v;
            v = 0;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        queue<int> q;
        vector<int> res;
        if (changed.size() & 1) {
            return {};
        }
        for(int e: changed){
            if(q.empty()) {
                q.push(e);
            }
            else{
                if((q.front() << 1) == e){
                    res.push_back(q.front());
                    q.pop();
                }
                else {
                    q.push(e);
                }
            }
        }
        if(!q.empty()) {
            return {};
        }
        return res;
    }
};