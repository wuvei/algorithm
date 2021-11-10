/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        while(fast && (fast = fast -> next) && (fast = fast -> next)) {
            if (head == fast)
                return true;
            head = head->next;       
        }
        return false;
    }
};