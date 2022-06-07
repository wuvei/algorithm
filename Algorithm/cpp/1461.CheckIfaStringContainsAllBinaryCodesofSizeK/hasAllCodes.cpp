// O(nk)
// Since the calculation of temp's hashcode is O(k) 
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (std::exp2(k) > s.size()) return false;
        unordered_set<string> appear;
        for (int i = 0; i <= s.size() - k; ++i) {
            string temp = s.substr(i, k);
            if (appear.find(temp) == appear.end())
                appear.emplace(temp);
        }
        return appear.size() == std::exp2(k);
    }
};

// O(n)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k) + k - 1)
            return false;

        int num = stoi(s.substr(0, k), nullptr, 2);
        unordered_set<int> exists = {num};
        
        for (int i = 1; i + k <= s.size(); ++i) {
            num = ((num - ((s[i - 1] - '0') << (k - 1))) << 1) + (s[i + k - 1] - '0');
            exists.insert(num);
        }
        return exists.size() == (1 << k);
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/solution/jian-cha-yi-ge-zi-fu-chuan-shi-fou-bao-h-1no1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
