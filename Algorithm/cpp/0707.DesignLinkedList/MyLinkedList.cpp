class MyLinkedList {
public:
    class Node {
    public:
        int val;
        shared_ptr<Node> next, prev;
        Node(int v): val(v) {}
    };
    MyLinkedList() {
        len = 0;
        head = make_shared<Node>(-1);
        tail = make_shared<Node>(-1);
        head->next = tail;
        tail->prev = head;
    }
    shared_ptr<Node> getNode(int index) {
        if (index < 0 || index >= len) {
            return nullptr;
        }
        bool isLeft = index < len / 2;
        if (!isLeft) {
            index = len - index - 1;
        }
        auto cur = isLeft ? head->next : tail->prev;
        while (index--) {
            cur = isLeft ? cur->next : cur->prev;
        }
        return cur;
    }
    int get(int index) {
        shared_ptr<Node> node = getNode(index);
        return node == nullptr ? -1 : node->val;
    }
    
    void addAtHead(int val) {
        auto new_node = make_shared<Node>(val);
        new_node->next = head->next;
        new_node->prev = head;
        head->next->prev = new_node;
        head->next = new_node;
        ++len;
    }
    
    void addAtTail(int val) {
        auto new_node = make_shared<Node>(val);
        new_node->prev = tail->prev;
        new_node->next = tail;
        tail->prev->next = new_node;
        tail->prev = new_node;
        ++len;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0 || index >= len) {
            if (index == 0) {
                addAtHead(val);
            }
            else if (index == len) {
                addAtTail(val);
            }
            return;
        }
        auto new_node = make_shared<Node>(val), cur = getNode(index);
        new_node->next = cur;
        new_node->prev = cur->prev;
        cur->prev->next = new_node;
        cur->prev = new_node;
        ++len;
    }
    
    void deleteAtIndex(int index) {    
        auto cur = getNode(index);
        if (cur == nullptr) return ;
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        cur.reset();
        --len;
    }
private:
    shared_ptr<Node> head, tail;
    int len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */