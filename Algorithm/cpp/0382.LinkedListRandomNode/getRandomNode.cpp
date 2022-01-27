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
// 蓄水池抽样
class Solution {
public:
    Solution(ListNode* h): head(h) {}

    int getRandom() {
        ListNode *node = head;
        int ans = head -> val, i = 1;
        while (node) {
            if (rand() % i == 0) ans = node -> val;
            node = node -> next;
            i++;
        }
        return ans;
    }
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */