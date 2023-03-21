class WordDictionary {
public:
    vector<vector<int>> tr;
    vector<bool> isWord;
    int idx;
    WordDictionary() {
        tr.resize(1, vector<int>(26));
        isWord.resize(1, false);
        idx = 0;
    }
    
    void addWord(string s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int u = s[i] - 'a';
            if (tr[p][u] == 0) {
                tr.push_back(vector<int>(26));
                isWord.push_back(false);
                tr[p][u] = ++idx;
            }
            p = tr[p][u];
        }
        isWord[p] = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, 0);
    }
    bool dfs(string &s, int trIdx, int sIdx) {
        int n = s.size();
        if (n == sIdx) return isWord[trIdx];
        char c = s[sIdx];
        if (c == '.') {
            for (int j = 0; j < 26; ++j) {
                if (tr[trIdx][j] != 0 && dfs(s, tr[trIdx][j], sIdx + 1)) return true;
            }
            return false;
        } else {
            int u = c - 'a';
            if (tr[trIdx][u] == 0) return false;
            return dfs(s, tr[trIdx][u], sIdx + 1);
        }
    }
};