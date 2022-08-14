// Binary Search
class MyCalendar {
    set<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        auto it = booked.lower_bound({end, 0});
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/my-calendar-i/solution/wo-de-ri-cheng-an-pai-biao-i-by-leetcode-nlxr/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// Segment Tree
class MyCalendar {
    // *************** 下面是模版 ***************
    class Node {
    public:
        Node *left, *right;
        int val, add;
    };
public: 
    void update(Node *node, int start, int end, int l, int r, int val) {
        if (l <= start && end <= r) {
            node->val += val;
            node->add += val;
            return;
        }
        pushDown(node);
        int mid = (start + end) >> 1;
        if (l <= mid) update(node->left, start, mid, l, r, val);
        if (r > mid) update(node->right, mid + 1, end, l, r, val);
        pushUp(node);
    }
    int query(Node *node, int start, int end, int l, int r) {
        if (l <= start && end <= r) return node->val;
        pushDown(node);
        int mid = (start + end) >> 1, ans = 0;
        if (l <= mid) ans = query(node->left, start, mid, l, r);
        if (r > mid) ans = max(ans, query(node->right, mid + 1, end, l, r));
        return ans;
    }
private:
    void pushUp(Node *node) {
        // 每个节点存的是当前区间的最大值
        node->val = max(node->left->val, node->right->val);
    }
    void pushDown(Node *node) {
        if (!node->left) node -> left = new Node();
        if (!node->right) node -> right = new Node();
        if (node -> add == 0) return;
        node->left->val += node->add;
        node->right->val += node->add;
        node->left->add += node->add;
        node->right->add += node->add;
        node->add = 0;
    }

private:
    const int N = static_cast<int>(1e9);
    Node *root;
public:
    MyCalendar() {
        root = new Node();
    }
    
    bool book(int start, int end) {
        // 先查询该区间是否为 0
        if (query(root, 0, N, start, end - 1) != 0) return false;
        // 更新该区间
        update(root, 0, N, start, end - 1, 1);
        return true;
    }
    
};

// 作者：lfool
// 链接：https://leetcode.cn/problems/my-calendar-i/solution/by-lfool-xvpv/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。