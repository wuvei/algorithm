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
    ListNode* swapPairs(ListNode* head) {
        if(head && head -> next){
            ListNode *pre = head, *cur = head -> next, *pp = NULL;
            head = cur;
            do{
                pre -> next = cur -> next;
                cur -> next = pre;
                if(pp)
                    pp -> next = cur;
                pp = pre;
            }while((pre = pre -> next) && (cur = pre -> next));
        }
        return head;
    }
};