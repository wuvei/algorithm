class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> a(arr);
        sort(a.begin(), a.end());
        unordered_map<int, int> m1, m2;
        int ans = 0, non_zero = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != arr[i]) {
                int temp1 = ++m1[a[i]];
                if (!temp1) --non_zero;
                else if (temp1 == 1)
                    ++non_zero;
                temp1 = --m1[arr[i]];
                if (!temp1) --non_zero;
                else if (temp1 == -1)
                    ++non_zero;
            }
            if (!non_zero) {
                ++ans;
            }
        }
        return ans;
    }
};

// prefix & suffix
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftmin(n, 0);
        leftmin[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; --i){
            leftmin[i] = min(arr[i], leftmin[i+1]);
        }
        int ans = 1, rightmax = arr[0];
        for(int i = 1; i < n; ++i){
            if(rightmax <= leftmin[i]) {
                ans++;
            }
            rightmax = max(rightmax, arr[i]);
        }
        
        return ans;
    }
};

// monotonic stack
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (auto& i : arr) {
            int max_i= st.empty() ? i : max(st.top(), i);
            while (!st.empty() && st.top() > i) {
                st.pop();
            }
            st.push(max_i);
        }
        return st.size();  
    }
};