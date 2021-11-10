#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node *, int> old2num;
        unordered_map<int, int> num2num;
        Node *h = head;
        int i = 0;
        while(h) {
            old2num[h] = i++;
            h = h -> next;
        }
        cout << i << endl;
        h = head;
        i = 0;
        while(h) {
            num2num[i++] = h -> random? old2num[h -> random]: -1;
            h = h -> next;
        }
        vector<Node*> copied(i);
        cout << i << endl;
        h = head;
        i = 0;
        while(h) {
            copied[i++] = new Node(h -> val);
            h = h -> next;
        }
        for (i = 0; i < copied.size(); i++) {
            if (num2num[i] == -1) copied[i] -> random = nullptr;
            else copied[i] -> random = copied[num2num[i]];
            if (i != copied.size() - 1) copied[i] -> next = copied[i + 1];
            else copied[i] -> next = nullptr;
        }
        return copied[0];
    }

    // Space O(1)
    // 原地复制
    Node* copyRandomList2(Node* head) {
        if (!head) return nullptr;
        Node *h = head;
        while (h) {
            Node *copy = new Node(h -> val);
            copy -> next = h -> next;
            h -> next = copy;
            h = copy -> next;
        }
        h = head;
        while (h) {
            if (h -> random) {
                h -> next -> random = h -> random -> next;
            }
            h = h -> next -> next;
        }
        Node *n_head = head -> next, *hh = n_head;
        h = head;
        while(h) {
            h -> next = h -> next -> next;
            h = h -> next;
            if (hh -> next) {
                hh -> next = hh -> next -> next;
                hh = hh -> next;
            }
        }
        return n_head;
    }
};

int main() {
    Solution s;
    Node *n = new Node(-1);
    s.copyRandomList(n);
    return 0;
}