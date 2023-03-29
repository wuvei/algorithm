class StreamChecker {
    struct Trie {
        Trie *arr[26]{nullptr};
        bool mark = false;
    };
    void insert(const string &s, Trie* t) const {
        for (char c : s) {
            int k = c - 'a';
            if (!t->arr[k]) t->arr[k] = new Trie();
            t = t->arr[k];
        }
        t->mark = 1;
    }
    bool find(Trie* t, char &c) {
        if (!t->arr[c - 'a']) return 0;
        else {
            t = t->arr[c - 'a'];
            q.push(t);
        }
        return t->mark;
    }
    Trie *head;
    queue<Trie *> q;
public:
    StreamChecker(vector<string>& words) {
        head = new Trie();
        for (auto &s : words) insert(s, head);
    }
    bool query(char letter) {
        bool flag = false;
        int k = q.size();
        while (k--) {
            flag |= find(q.front(), letter);
            q.pop();
        }
        return find(head, letter) | flag;
    }
};

// 作者：ztzyfc
// 链接：https://leetcode.cn/problems/stream-of-characters/solutions/1682208/zi-dian-shu-wei-hu-duo-ge-zhi-zhen-by-ya-euzn/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。