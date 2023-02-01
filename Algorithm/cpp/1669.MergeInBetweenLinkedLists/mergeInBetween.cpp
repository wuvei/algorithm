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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int idx = 0;
        ListNode *node = list1;
        for (;idx < a - 1; ++idx) {
            node = node->next;
        }
        ListNode *cutoff = node;
        for (;idx < b; ++idx) {
            node = node->next;
        }
        cutoff->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = node->next;
        return list1;
    }
};