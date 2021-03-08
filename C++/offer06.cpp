
#include "stdfax.h"
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        ListNode *tmp = head;
        ListNode *newList = nullptr;
        while (head != nullptr)
        {
            tmp = head;
            head = head->next;
            tmp->next = newList;
            newList = tmp;
        }
        tmp = newList;
        vector<int> res(0);
        while (tmp != nullptr)
        {
            res.push_back(tmp->val);
            tmp = tmp->next;
        }
        return res;
    }
};