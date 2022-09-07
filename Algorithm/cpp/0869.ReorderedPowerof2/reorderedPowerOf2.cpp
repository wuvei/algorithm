unordered_set<string> f() {
    unordered_set<string> s;
    for (int i = 0; i < 32; ++i) {
        int x = 1 << i;
        string temp = to_string(x);
        sort(temp.begin(), temp.end());
        s.insert(std::move(temp));
    }
    return std::move(s);
}
class Solution {
public:
    static unordered_set<string> candidate;
    bool reorderedPowerOf2(int n) {
        string temp = to_string(n);
        sort(temp.begin(), temp.end());
        return candidate.find(temp) != candidate.end();
    }
};
unordered_set<string> Solution::candidate = f();