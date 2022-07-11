// Trie
class Trienode {
public:    
    shared_ptr<Trienode> data[26];
};
class Solution {
public:
    int dfs(shared_ptr<Trienode> root, int d) {
        int ans = 0;
        bool flag = true;
        for (auto &node: root -> data) {
            if (node) {
                ans += dfs(node, d + 1);
                flag = false;
            }
        }
        if (flag) {
            ++nums;
            return d;
        }
        return ans;
    }
    int minimumLengthEncoding(vector<string>& words) {
        auto root = make_shared<Trienode>(), node = root;
        for (string &s: words) {
            node = root;
            for (auto it = s.crbegin() ; it != s.crend(); ++it) {
                auto &temp = node -> data[*it - 'a'];
                if (!temp)
                    temp = make_shared<Trienode>();
                node = temp;
            }
        }
        return dfs(root, 0) + nums;
    }
private:
    int nums;
};

// Suffix, Sort
class Trienode {
public:    
    shared_ptr<Trienode> data[26];
};
class Solution {
public:
    static bool compare(string& s1, string& s2) {
        int N1 = s1.length();
        int N2 = s2.length();
        for (int i = 0; i < min(N1, N2); i++) {
            char c1 = s1[N1-1-i];
            char c2 = s2[N2-1-i];
            if (c1 != c2) {
                return c1 < c2;
            }
        }
        return N1 < N2;
    }

    int minimumLengthEncoding(vector<string>& words) {
        int N = words.size(), ans = 0;  
        sort(words.begin(), words.end(), compare);
        for (int i = 0; i < N - 1; i++) {
            if (!endsWith(words[i + 1], words[i])) {
                ans += words[i].length() + 1;
            }
        }
        ans += words.back().length() + 1;
        return ans;
    }
    bool endsWith(string& s, string& t) {
        int N1 = s.length();
        int N2 = t.length();
        if (N1 < N2) {
            return false;
        }
        for (int i = 0; i < N2; i++) {
            if (s[N1-N2+i] != t[i]) {
                return false;
            }
        }
        return true;
    }

};