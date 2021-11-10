class Node {
public:
    string key;
    int value;
    Node* prev;
    Node* next;
    Node* up;
    Node* down;

    Node() : key(""), value(0), prev(NULL), next(NULL), up(NULL), down(NULL) {}
    Node(string& _key) : key(_key), value(1), prev(NULL), next(NULL), up(NULL), down(NULL) {}
};

class HList {
public:
    Node pseudoHead;
    Node pseudoTail;

    HList() {
        pseudoHead.next = &pseudoTail;
        pseudoTail.prev = &pseudoHead;
        pseudoTail.value = INT_MAX;
    }

    void insert(Node* prevNode, Node* node, Node* nextNode) {
        if (node->value == prevNode->value) {
            prevNode->prev->next = node;
            node->prev = prevNode->prev;
            node->next = nextNode;
            nextNode->prev = node;
            node->down = prevNode;
            prevNode->up = node;
            prevNode->prev = prevNode->next = NULL;
        }
        else if (node->value == nextNode->value) {  // 相同的要合并，放到当前节点下面
            prevNode->next = node;
            node->prev = prevNode;
            node->next = nextNode->next;
            nextNode->next->prev = node;
            node->down = nextNode;
            nextNode->up = node;
            nextNode->prev = nextNode->next = NULL;  // 纯纵向节点没有前后
        }
        else {
            prevNode->next = node;
            node->prev = prevNode;
            node->next = nextNode;
            nextNode->prev = node;
        }
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        if (node->down == NULL) {  // 这一列只剩这一个节点了，直接删除
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        else {  // 这一列还有其它节点，删了首节点第二个顶上来
            prevNode->next = node->down;
            node->down->prev = prevNode;
            node->down->next = nextNode;
            nextNode->prev = node->down;
        }
    }
};

class VList {
public:
    Node pseudoTop;
    Node pseudoBottom;
    int size;

    VList() {
        pseudoTop.down = &pseudoBottom;
        pseudoBottom.up = &pseudoTop;
        size = 0;
    }

    void insert(Node* node) {  // 只能插入在头部
        node->up = &pseudoTop;
        node->down = pseudoTop.down;
        pseudoTop.down->up = node;
        pseudoTop.down = node;
        ++size;
    }

    void remove(Node* node) {
        node->up->down = node->down;
        node->down->up = node->up;
        if (--size == 0) {
            node->up = node->down = NULL;  // 删光之后要置空，因为删除横向的时候会判断纵向还有没有节点
        }
    }
};

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (keyNodes.count(key) == 0) {
            Node* node = new Node(key);
            keyNodes[key] = node;
            insert(&hlist.pseudoHead, node, hlist.pseudoHead.next);  // 新的节点肯定插入在pseudoHead后面
        }
        else {
            Node* node = keyNodes[key];
            Node* prev = valueLists[node->value].pseudoTop.down->prev;
            Node* next = valueLists[node->value].pseudoTop.down->next;
            remove(node);  // 先删除这个节点
            ++node->value;
            if (node->down == NULL) {  // 原来那一列已经没有了
                insert(prev, node, next);
            }
            else {
                insert(valueLists[node->value - 1].pseudoTop.down, node, next);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyNodes.count(key) == 0) {
            return;
        }

        Node* node = keyNodes[key];
        Node* prev = valueLists[node->value].pseudoTop.down->prev;
        Node* next = valueLists[node->value].pseudoTop.down->next;
        remove(node);  // 先删除这个节点
        if (--node->value == 0) {  // 减为0了就彻底干掉
            keyNodes.erase(key);
            delete node;
        }
        else {  // 计数减1后再重新插入
            if (node->down == NULL) {  // 原来那一列已经没有了
                insert(prev, node, next);
            }
            else {
                insert(prev, node, valueLists[node->value + 1].pseudoTop.down);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return hlist.pseudoHead.next == &hlist.pseudoTail ?  "" : hlist.pseudoTail.prev->key;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return hlist.pseudoHead.next == &hlist.pseudoTail ? "" : hlist.pseudoHead.next->key;
    }

    void remove(Node* node) {
        VList& vlist = valueLists[node->value];
        vlist.remove(node);  // 先从纵向队列删除

        if (vlist.size == 0) {
            valueLists.erase(node->value);
        }

        if (node->prev != NULL) {
            hlist.remove(node);  // 再从横向队列删除
        }
    }

    void insert(Node* prev, Node* node, Node* next) {
        valueLists[node->value].insert(node);
        hlist.insert(prev, node, next);
    }

private:
    unordered_map<string, Node*> keyNodes;
    unordered_map<int, VList> valueLists;
    HList hlist;
};

// 作者：wen-rou-yi-dao-123
// 链接：https://leetcode-cn.com/problems/all-oone-data-structure/solution/shi-zi-lian-biao-wan-cheng-quan-o1cao-zu-iww6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */



class AllOne {
public:
    /** Initialize your data structure here. */
    struct Node{
        unordered_set<string> container;
        int val = 0;
        Node(int v):val(v){}
    };
    unordered_map<string, list<Node>::iterator> kv;
    list<Node> List;
    AllOne() {}
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(kv.count(key)){
            auto oldNode = kv[key];
            auto newNode = next(oldNode, 1);
            if(newNode == List.end() || newNode->val>oldNode->val+1){
                newNode = List.insert(newNode, Node(oldNode->val+1));
            }

            newNode->container.insert(key);
            oldNode->container.erase(key);

            if(oldNode->container.empty()){
                List.erase(oldNode);
            }
            kv[key] = newNode;
        } else {
            auto newNode = List.begin();
            if(List.empty() || List.begin()->val>1)
                newNode = List.insert(List.begin(), Node(1));
            newNode->container.insert(key);
            kv[key] = newNode;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(kv.count(key)){
            auto oldNode = kv[key];
            if(oldNode->val==1) {
                kv.erase(key);
            } else {
                auto newNode = next(oldNode, -1);
                if(oldNode==List.begin() || newNode->val<oldNode->val-1){
                    newNode = List.insert(oldNode, Node(oldNode->val-1));
                }
                newNode->container.insert(key);
                kv[key] = newNode;
            }

            oldNode->container.erase(key);
            if(oldNode->container.empty()){
                List.erase(oldNode);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(List.empty()) return "";
        return *List.rbegin()->container.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(List.empty()) return "";
        return *List.begin()->container.begin();
    }
};

// 作者：lwpyr
// 链接：https://leetcode-cn.com/problems/all-oone-data-structure/solution/c-ha-xi-kvshuang-xiang-lian-biao-by-lwpyr/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。