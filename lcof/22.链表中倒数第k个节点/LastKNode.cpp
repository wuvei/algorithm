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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode *first = head, *second = head;
        int count = 0;
        while(first -> next) {
            first = first -> next;
            count++;
            if (count >= k - 1) second = second -> next;
        }
        return second;
    }
};