/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *head, *tail;
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        head = tail = nullptr;
        build(root);
        head -> left = tail;
        tail -> right = head;
        return head;
    }

    void build(Node *root) {
        if (!root) return;
        if (root -> left) build(root -> left);
        if (!head) {
            head = tail = root;
        } else {
            tail -> right = root;
            root -> left = tail;
            tail = root;
        }
        if (root -> right) build(root -> right);
    }

    // Morris 遍历
    Node* treeToDoublyList2(Node* root) {
        if(!root) return nullptr;
        Node *head=nullptr, *last=nullptr, *temp=nullptr, *next;
        while(root){
            if(root -> left){//对应步骤2，这里原算法需要遍历后不改变树结构，而本题需要连接前后遍历的两节点
                if(root -> left -> right == root){//判断此节点是否已经和前一节点连接
                    last = root;
                    root = root->right;
                }else { //和前一节点连接，并转移到原来的左节点
                    temp = root -> left, next = temp;
                    while(temp -> right) temp = temp->right;//寻找左子节点的最右子节点（包括本身），即前一节点
                    temp -> right = root;
                    root -> left = temp;
                    root = next;
                }
            } else { //对应步骤1，但是这里需要记录树中最小节点head，以及连接last，即前一节点
                if(!head) head = root;
                if(last) {
                    last -> right = root;
                    root -> left = last;
                }
                last = root;
                root = root -> right;
            }
        }
        last -> right = head;
        head -> left = last;
        return head;
    }
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/fei-di-gui-morrisbian-li-gua-yong-yu-you-5qbj/
};