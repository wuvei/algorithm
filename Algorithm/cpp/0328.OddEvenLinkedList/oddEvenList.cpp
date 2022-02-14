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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode *odd = head, *evenHead = head -> next, *even = evenHead, *node = evenHead -> next;
        int count = 1;
        while (node) {
            if (count & 1) {
                odd -> next = node;
                odd = node;
            }
            else {
                even -> next = node;
                even = node;
            }
            node = node -> next;
            count++;
        }
        odd -> next = evenHead;
        even -> next = nullptr;
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode *odd = head, *evenHead = head -> next, *even = evenHead, *node = evenHead -> next;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
