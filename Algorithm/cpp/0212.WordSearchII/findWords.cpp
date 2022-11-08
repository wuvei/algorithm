class Node{
public:
    std::shared_ptr<Node> node[26];
    bool flag;
    string w;
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
        p->w = word;
	}

	bool search(string &word) {
		auto p = root;
		for(int i = 0; i < word.length() && p != nullptr; ++i){
			if(p->node[word[i]-97] == nullptr){
				return false;
			}
			p = p->node[word[i]-97];
		}
		
		return (p->flag) ? true : false;
	}
};

class Solution {
public:
    unordered_set<string> ans;
    Trie trie;
    int m, n;
    vector<vector<bool>> visit;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int x, int y, vector<vector<char>>& board, std::shared_ptr<Node> p) {
        visit[x][y] = true;
        if (p->flag) {
            ans.insert(p->w);
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny] && p->node[board[nx][ny] - 97]) {
                dfs(nx, ny, board, p->node[board[nx][ny] - 97]);
            }
        }
        visit[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for (auto &s: words) {
            trie.insert(s);
        }
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (trie.root->node[board[i][j] - 97]) {
                    visit.resize(m, vector<bool>(n, false));
                    dfs(i, j, board, trie.root->node[board[i][j] - 97]);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};