class Node{
public:
    std::shared_ptr<Node> node[26];
    bool flag;
};
class Trie {
public:
	std::shared_ptr<Node> root;
	Trie() {
		root = std::make_shared<Node>();
	}
	void insert(string &word) {
		auto p = root;
		for(int i = 0; i < word.length(); ++i) {
			if(p->node[word[i] - 97] == nullptr){
				p->node[word[i] - 97] = make_shared<Node>();
			}
			p = p->node[word[i] - 97];
		}
		p->flag = true;
	}

	int search(string &word, int idx) {
		auto p = root;
		for(int i = idx; i < word.length() && p != nullptr; ++i){
			if (p->node[word[i]-97] == nullptr){
				return INT_MAX;
			}
            if (p->node[word[i]-97]->flag == true) {
                int k = search(word, i+1);
                if (k != INT_MAX) return k + 1;
            }
            p = p->node[word[i]-97];
		}
		return idx == word.size() ? 0 : INT_MAX;
	}
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string &a, const string &b){
            return a.size() == b.size() ? a < b : a.size() < b.size();
        });
        vector<string> ans;
        Trie t;
        for (string &w: words) {
            int x = t.search(w, 0);
            if (x != INT_MAX && x >= 2) ans.push_back(w);
            t.insert(w);
        }
        return ans;
    }
};