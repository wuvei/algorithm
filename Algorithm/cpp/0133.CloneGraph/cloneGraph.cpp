/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* ,Node*> mp;
    Node* dfs(Node* node) {
        if (mp.find(node) != mp.end())
            return mp[node];
        Node *cur = new Node(node->val);
        mp[node] = cur;
        for (Node *next : node->neighbors) {
            cur->neighbors.push_back(dfs(next));
        }
        return cur;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }
};