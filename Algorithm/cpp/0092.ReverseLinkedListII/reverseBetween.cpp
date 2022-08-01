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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(), *prev = dummy;
        dummy -> next = head;
        for (int i = 1; i < left; ++i) {
            prev = head;
            head = head -> next;
        }
        ListNode *node = head, *nn = nullptr;
        for (int i = left; i <= right; ++i) {
            ListNode *temp = head -> next;
            head -> next = nn;
            nn = head;
            head = temp;
        }
        node -> next = head;
        prev -> next = nn;
        return dummy -> next;
    }
};