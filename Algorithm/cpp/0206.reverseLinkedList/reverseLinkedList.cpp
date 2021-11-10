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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode *> ss;
        
        while(head){
            ss.push(head);
            head = head -> next;
        }
        if(!ss.empty()){
            head = ss.top();
            ss.pop();
        }
        ListNode *pre = head, *cur;
        while(!ss.empty()){
            cur = ss.top();
            pre -> next = cur;
            pre = cur;
            ss.pop();
        }
        cur -> next = NULL;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* newNode = nullptr;
        while(!head){
            ListNode* next = head -> next;
            head -> next = newNode;
            newNode = head;
            head = next;
        }
        return newNode;
        
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return node;
    }

};