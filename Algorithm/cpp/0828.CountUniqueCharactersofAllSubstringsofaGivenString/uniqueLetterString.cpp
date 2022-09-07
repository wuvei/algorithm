class Solution {
public:
    int uniqueLetterString(string s) {
        vector<pair<int, int>> v(26, {-1, -1});
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            v[s[i] - 'A'].first = v[s[i] - 'A'].second;
            v[s[i] - 'A'].second = i;
            for(auto &j : v) {
            	ans += (j.second - j.first);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> index;
        for (int i = 0; i < s.size(); i++) {
            index[s[i]].emplace_back(i);
        }
        int res = 0;
        for (auto &&[_, arr]: index) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size() - 1; i++) {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/solution/tong-ji-zi-chuan-zhong-de-wei-yi-zi-fu-b-h9pj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。