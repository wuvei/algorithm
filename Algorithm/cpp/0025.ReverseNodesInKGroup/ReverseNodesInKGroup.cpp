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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)  return head;
        ListNode *cur = head, *pre = NULL;
        ListNode **temp = new ListNode*[k];
        bool flag = true;
        int count = 0;
        while(cur){
            for(int i = 0; i < k; i++){
                if(cur){
                    temp[i] = cur;
                    cur = cur -> next;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(pre) pre -> next = temp[k - 1];
                temp[0] -> next = temp[k - 1] -> next;
                for(int i = k - 1; i >= 1; i--){
                    temp[i] -> next = temp[i - 1];
                }
                pre = temp[0];
                count++;
                if(count == 1)
                    head = temp[k - 1];
            }
            
        }
        
        delete []temp;
        return head;
        
    }
};