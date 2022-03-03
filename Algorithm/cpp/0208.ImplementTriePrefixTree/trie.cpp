class Trie {
public:
    class TrieNode {
    public:
        TrieNode* son[26];
        bool isEnd;
        TrieNode(): isEnd(false) {
            for (int i = 0; i < 26; i++)
                son[i] = nullptr;
        }
        ~TrieNode() {
            for (auto s: son)
                if (s) delete s;
        }
    };
    
    Trie(): root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode *cur = root;
        for (char c: word) {
            int idx = c - 'a';
            if (!cur->son[idx])
                cur -> son[idx] = new TrieNode();
            cur = cur->son[idx];
        }
        cur -> isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for (char c: word) {
            if (!cur) break;
            cur = cur->son[c - 'a'];
        }
        return cur? cur -> isEnd: false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (char c: prefix) {
            if (!cur) break;
            cur = cur->son[c - 'a'];
        }
        return cur;
    }
   
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */