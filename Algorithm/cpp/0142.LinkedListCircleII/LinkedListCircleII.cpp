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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *low = head;
        while(fast && (fast = fast -> next) && (fast = fast -> next)){
            low = low -> next;
            if(low == fast){
                while(fast != head){
                    fast = fast -> next;
                    head = head -> next;
                }
                return fast;
            }
        }
        return NULL;
    }
};