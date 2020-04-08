#include <iostream>
using namespace std;

// doesnt matter to us, just given in leetcode
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *middleNodeByINDEX(ListNode *head) // first middle node is our mid in even size.
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 876. MERE WALA======================================

ListNode *middleNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 876. SIR WALA =====================================

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return fast->next == nullptr ? slow : slow->next;
}

// 206. =============================================

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *forw = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        forw = curr->next; //backup.

        curr->next = prev; // link join.

        prev = curr; // move forward.
        curr = forw;
    }
    return prev;
}

// 234. ===========================================================

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *forw = nullptr;

        while (curr != nullptr)
        {
            forw = curr->next; //backup.

            curr->next = prev; // link join.

            prev = curr; // move forward.
            curr = forw;
        }

        return prev; // new head.
    }
    ListNode *middleNodeByINDEX(ListNode *head)
    { // first middle node is our mid in even size.
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == NULL)
            return true;

        ListNode *mid = middleNodeByINDEX(head);
        ListNode *nhead = mid->next;
        mid->next = NULL;

        nhead = reverseList(nhead);

        while (head != NULL && nhead != NULL)
        {
            if (head->val != nhead->val)
            {
                return false;
            }
            head = head->next;
            nhead = nhead->next;
        }
        return true;
    }
};