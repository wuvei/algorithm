/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        vector<ListNode*> listscopy(lists);
        queue<int> q;
        ListNode *head = new ListNode(), *node = head;
        listscopy.erase( remove(listscopy.begin(), listscopy.end(), nullptr), listscopy.end());
        while (listscopy.size()) {
            int min_val = INT_MAX, record = -1;
            for (int i = 0; i < listscopy.size(); i++) {
                if (!listscopy[i]) q.push(i);
                else {
                    if (listscopy[i] -> val < min_val) {
                        record = i;
                        min_val = listscopy[i] -> val;
                    }
                }
            }
            if (record != -1) {
                node -> next = listscopy[record];
                node = node -> next;
                listscopy[record] = listscopy[record] -> next;
            }
            
            while(!q.empty()) {
                listscopy.erase(listscopy.begin() + q.front());
                q.pop();
            }
        }
        return head -> next;
    }
};


class Solution2 {
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode head, *node = &head;
        while (a && b) {
            if (a -> val < b -> val) {
                node -> next = a;
                a = a -> next;
            }
            else {
                node -> next = b;
                b = b -> next;
            }
            node = node -> next;
        }
        if (a) node -> next = a;
        else node -> next = b;
        return head.next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return merge2Lists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        lists.erase( remove(lists.begin(), lists.end(), nullptr), lists.end());
        return merge(lists, 0, lists.size() - 1);
    }
};