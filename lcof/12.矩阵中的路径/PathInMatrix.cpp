#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <stack>
using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size() || !board[0].size() || word == "") return false;
        stack<pair<int, int> > s0, s;
        stack<int> search_num;
        int rows = board.size(), cols = board[0].size();
        if (rows * cols < word.size()) return false;
        // find the first char in word
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    s0.push(make_pair(i, j));
                }
            }
        }
        if (word.size() == 1) return (s0.size())? true: false;
        int to_find = 1;
        int dirx[] = {0, 0, 1, -1}, diry[] = {1, -1, 0, 0};
        bool *visited = new bool[rows * cols], found = false;
        memset(visited, 0, rows * cols);
        // search
        while(!s0.empty() && !found) {
            pair<int, int> p = s0.top();
            s0.pop();
            s.push(p);
            search_num.push(0);
            to_find = 1;
            while (!s.empty() && !found) {
                p = s.top();
                visited[p.first * cols + p.second] = true;
                int i = search_num.top();
                for (; i < 4; i++) {
                    int exp_x = p.first + dirx[i], exp_y = p.second + diry[i];
                    if (exp_x >= 0 && exp_x < board.size() && exp_y >= 0 && exp_y < board[exp_x].size() && !visited[exp_x * cols + exp_y] && board[exp_x][exp_y] == word[to_find]) {
                        to_find++;
                        if (to_find == word.size()) {
                            found = true;
                            break;
                        }
                        s.push(make_pair(exp_x, exp_y));
                        search_num.pop();
                        search_num.push(i + 1);
                        search_num.push(0);
                        break;
                    }
                }

                if (i == 4 && !found) {
                    s.pop();
                    search_num.pop();
                    visited[p.first * cols + p.second] = false;
                    to_find--;
                }
                
            }
        }
        delete []visited;        
        return found;
    }
};

int main() {
    Solution s;
    vector<vector<char> > v(3);
    v[0] = vector<char>({'A','B','C','E'});
    v[1] = vector<char>({'S','F','C','S'});
    v[2] = vector<char>({'A','D','E','E'});
    string word = "ABCCED";
    cout << s.exist(v, word) << endl;
    return 0;
}