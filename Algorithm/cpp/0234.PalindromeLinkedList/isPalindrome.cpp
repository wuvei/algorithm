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
    ListNode *rerv(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode *tail = rerv(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return tail;
    }
    bool isPalindrome(ListNode* head) {
        if (!head -> next) return true;
        ListNode *fast = head, *slow = head;
        while(fast) {
            slow = slow -> next;
            fast = fast -> next;
            if (fast) fast = fast -> next;
        }
        slow = rerv(slow);
        while (slow) {
            if (head -> val != slow -> val) return false;
            head = head -> next;
            slow = slow -> next;
        }
        return true;
    }
};


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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = slow -> next;
        slow -> next = nullptr;
        
        // Reverse list
        ListNode *pre = nullptr;
        while (fast) {
            ListNode *latter = fast -> next;
            fast -> next = pre;
            pre = fast;
            fast = latter;
        }
        
        while (head && pre) {
            if (head -> val != pre -> val) return false;
            head = head -> next;
            pre = pre -> next;
        }
        return true;
    }
};