class Solution {
public:
    void check(char cur, int count, int k) {
        if (!l.empty()) {
            auto [pre, count_pre] = l.back();
            if (cur == pre) {
                l.pop_back();
                count += count_pre;
                if (count >= k) count -=k;
            }
        }
        if (count) l.push_back({cur, count}); 
    }
    string removeDuplicates(string s, int k) {
        char cur = s[0];
        int count = 0;
        for (char c: s) {
            if (c == cur) {
                ++count;
                if (count == k) count = 0;
            }
            else {
                if (count) check(cur, count, k);
                cur = c;
                count = 1;
            }
        }
        check(cur, count, k);
        string ans;
        while (!l.empty()) {
            auto &p = l.front();
            ans += string(p.second, p.first);
            l.pop_front();
        }
        return ans;
    }
private:
    list<pair<char, int> > l;
};


// stack
class Solution {
public:
   string removeDuplicates(string s, int k) {
        stack<int> counts;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                counts.push(1);
            } else if (++counts.top() == k) {
                counts.pop();
                s.erase(i - k + 1, k);
                i = i - k;
            }
        }
        return s;
    }
};

// stack 2
class Solution {
public:
   string removeDuplicates(string s, int k) {
        vector<pair<int, char>> counts;
        for (int i = 0; i < s.size(); ++i) {
            if (counts.empty() || s[i] != counts.back().second) {
                counts.push_back({ 1, s[i] });
            } else if (++counts.back().first == k) {
                counts.pop_back();
            }
        }
        s = "";
        for (auto &p : counts) {
            s += string(p.first, p.second);
        }
        return s;
    }
};


// https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii/solution/shan-chu-zi-fu-chuan-zhong-de-suo-you-xiang-lin--4/