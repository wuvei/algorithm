
struct Node
{
    int weight;
    bool isWord;
    Node* children[27];

    Node() {
        memset(children, 0, sizeof(children));
        weight = -1;
        isWord = false;
    }
};

class WordFilter {
private:
    Node* root = new Node();

public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int weight = 0; weight < n; ++weight) {
            string fullWord = words[weight] + "#" + words[weight];
            int nWord = words[weight].size();
            for (int i = 0; i < nWord + 1; ++i) {
                Node* curr = root;
                for (int j = i; j < fullWord.size(); ++j) {
                    int index = fullWord[j] == '#' ? 26 : fullWord[j]-'a';
                    if (!curr->children[index])
                        curr->children[index] = new Node();
                    curr = curr->children[index];
                    if (j > nWord) {
                        curr->isWord = true;
                        curr->weight = weight;
                    }
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string fullWord = suffix + "#" + prefix;
        Node* curr = root;
        for (char c : fullWord)
        {
            int index = c == '#' ? 26 : c-'a';
            if (!curr->children[index])
                return -1;
            curr = curr->children[index];
        }
        return curr->isWord ? curr->weight : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */