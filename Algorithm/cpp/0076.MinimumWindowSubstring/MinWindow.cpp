#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, need[128] = {}, cnt = t.size();
        int minStart = 0, minLen = INT_MAX;
        for (char c: t) need[c]++;
    
        for (; right < s.size(); right++) {
            if (need[s[right]] > 0) cnt--;
            need[s[right]]--;
            while(cnt == 0) {
                if (++need[s[left]] > 0) cnt++;
                left++;
                if (cnt > 0 && right - left + 2 < minLen) {
                    minLen = right - left + 2;
                    minStart = left - 1;
                }
            }
        }
        if (minLen != INT_MAX) return s.substr(minStart, minLen);
        return "";
    }
};

// Debug
// class Solution {
// public:
//     void pp (int a[]) {
//         for (int i = 0; i < 128; i++) {
//             if (a[i] > 0) cout << char(i) << ": " << a[i] << " ";
//         }
//         cout << endl;
//     }
//     string minWindow(string s, string t) {
//         int left = 0, right = 0, need[128] = {}, cnt = t.size();
//         int minStart = 0, minLen = INT_MAX;
//         for (char c: t) need[c]++;
//         pp(need);
//         for (; right < s.size(); right++) {
//             cout << "left: " << left << ", right: " << right << ", cnt: " << cnt << endl;
//             if (need[s[right]] > 0) cnt--;
//             need[s[right]]--;
//             pp(need);
//             while(cnt == 0) {
//                 cout << "right: " << right << ", left: " << left << endl;
//                 if (++need[s[left]] > 0) cnt++;
//                 left++;
//                 if (cnt > 0 && right - left + 2 < minLen) {
//                     minLen = right - left + 2;
//                     minStart = left - 1;
//                 }
//             }
//         }
//         if (minLen != INT_MAX) return s.substr(minStart, minLen);
//         return "";
//     }
// };


class Solution2 {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, need[128] = {}, cnt = t.size();
        int minStart = 0, minLen = INT_MAX;
        for (char c: t) need[c]++;
        for (; right < s.size(); right++) {
            char cur = s[right];
            if (need[cur] > 0) cnt--;
            need[cur]--;
            while(!cnt) {
                
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                if (++need[s[left]] > 0) cnt++;
                left++;
            }
        }
        if (minLen != INT_MAX) return s.substr(minStart, minLen);
        return "";
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution sol;
    string ret = sol.minWindow(s, t);
    cout << "ret: " << ret << endl;
    return 0;
}