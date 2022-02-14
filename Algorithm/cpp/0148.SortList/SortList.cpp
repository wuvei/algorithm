#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;

        //get mid which will be at s pointer
        ListNode *s = head, *f = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }

        //split list
        f = s->next;
        s->next = NULL;

        //get first half sorted
        head = sortList(head);
        //get second half sorted
        f = sortList(f);
        //merge the 2 sorted halves to get the sorted List
        head = merge(head, f);
        return head;
    }

    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *n = NULL;
        ListNode *temp = NULL;

        while (a && b) {
            if (a->val < b->val) {
                if (!n)
                    n = temp = a;
                else {
                    temp->next = a;
                    temp = temp->next;
                }
                a = a->next;
            }
            else
            {
                if (!n)
                    n = temp = b;
                else {
                    temp->next = b;
                    temp = temp->next;
                }
                b = b->next;
            }
        }
        if (a)
            temp->next = a;
        if (b)
            temp->next = b;
        return n;
    }
};

class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto slow = head, fast = head;
        while (fast->next && fast->next->next)
            slow = slow->next, fast = fast->next->next;
        // 切链
        fast = slow->next, slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode sub(0), *ptr = &sub;
        while (l1 && l2) {
            auto &node = l1->val < l2->val ? l1 : l2;
            ptr = ptr->next = node, node = node->next;
        }
        ptr->next = l1 ? l1 : l2;
        return sub.next;
    }
};

class Solution3 {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        int length = 0;
        ListNode* node = head;
        while (node) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode *prev = dummyHead, *curr = dummyHead->next;
            while (curr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next; i++)
                    curr = curr->next;
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr && curr->next; i++)
                    curr = curr->next;
                ListNode* next = nullptr;
                if (curr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next) prev = prev->next;
                curr = next;
            }
        }
        return dummyHead->next;
    }

   ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0), *ptr = &dummyHead;
        while (l1 && l2) {
            auto &node = l1->val < l2->val ? l1 : l2;
            ptr = ptr->next = node;
            node = node->next;
        }
        ptr->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

int main()
{
    int data[] = {-1, 5, 3, 4, 0};
    int length = sizeof(data) / sizeof(data[0]);
    ListNode *array = new ListNode[length];
    array[0] = ListNode(data[0]);
    ListNode *current = array;

    for (int i = 1; i < length; i++)
    {
        array[i] = ListNode(data[i]);
        current->next = array + i;
        current = array + i;
    }
    current = array;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    Solution sol;
    current = sol.sortList(array);
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    delete[] array;
    return 0;
}