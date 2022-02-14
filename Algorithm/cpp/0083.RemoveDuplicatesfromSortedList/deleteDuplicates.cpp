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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *one = head, *node = head -> next;
        while (node) {
            if (node -> val == one -> val) {
                one -> next = node -> next;
                delete node;
                node = one -> next;
            }
            else {
                one = node;
                node = node -> next;
            }
        }
        return head;
    }
};