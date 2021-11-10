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
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        //get mid which will be at s pointer
        ListNode *s = head, *f = head;
        while (f->next && f->next->next)
        {
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

        while (a && b)
        {
            if (a->val < b->val)
            {
                if (!n)
                    n = temp = a;
                else
                {
                    temp->next = a;
                    temp = temp->next;
                }
                a = a->next;
            }
            else
            {
                if (!n)
                    n = temp = b;
                else
                {
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