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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> id, st;
        vector<int> ans;
        while (head) {
            ans.push_back(0);
            while (!st.empty() && st.top() < head->val) {
                ans[id.top()] = head->val;
                st.pop();
                id.pop();
            }
            st.push(head->val);
            id.push(ans.size() - 1);
            head = head->next;
        }
        return std::move(ans);
    }
};