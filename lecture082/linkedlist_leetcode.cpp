
// 141. =========================================

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }
        return slow == fast;
    }
};

// 142. =========================================

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        if (slow == fast) // means cycle detected
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return nullptr;
    }
};

// 160. ============================================

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }

        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        if (headA->next == nullptr && headB->next == nullptr && headA->val == headB->val)
        {
            return headA;
        }

        ListNode *tail = nullptr;
        ListNode *curr = headA;

        while (curr != nullptr)
        {
            tail = curr;
            curr = curr->next;
        }

        tail->next = headB;
        ListNode *ans = detectCycle(headA);
        tail->next = nullptr;
        return ans;
    }
};

//  21. ================================================

ListNode *mergeTwoLists(ListNode *a, ListNode *b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    ListNode *head = new ListNode(0);
    ListNode *curr = head;

    while (a != NULL && b != NULL)
    {
        if (a->val <= b->val)
        {
            curr->next = a;
            a = a->next;
        }
        else
        {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }

    if (a != nullptr)
        curr->next = a;
    if (b != nullptr)
        curr->next = b;

    return head->next;
}

// 148. ========================================================
//* MERGE SORT , complexcity : O(nlog(n))

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

ListNode *mergeTwoLists(ListNode *A, ListNode *B)
{
    if (A == nullptr)
        return B;
    if (B == nullptr)
        return A;

    ListNode *head = new ListNode(0); // dummyNode;
    ListNode *curr = head;

    while (A != nullptr && B != nullptr)
    {
        if (A->val <= B->val)
        {
            curr->next = A;
            A = A->next;
        }
        else
        {
            curr->next = B;
            B = B->next;
        }
        curr = curr->next;
    }

    if (A != nullptr)
        curr->next = A;
    else if (B != nullptr)
        curr->next = B;

    return head->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *mid = middleNodeByINDEX(head);
    ListNode *nhead = mid->next;
    mid->next = nullptr;

    ListNode *a = sortList(head);
    ListNode *b = sortList(nhead);
    return mergeTwoLists(a, b);
}

// 23. ==============================================
//* normal method ===================================
//* method is named as DIVIDE AND CONQURE

ListNode *mergeLists(ListNode *a, ListNode *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    ListNode *head = new ListNode(0);
    ListNode *curr = head;

    while (a != nullptr && b != nullptr)
    {
        if (a->val <= b->val)
        {
            curr->next = a;
            a = a->next;
        }
        else
        {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }

    if (a != NULL)
        curr->next = a;
    if (b != NULL)
        curr->next = b;

    return head->next;
}

ListNode *mergeKLists_(vector<ListNode *> &list, int si, int ei)
{
    if (si == ei)
        return list[si];

    if (si + 1 == ei)
        return mergeLists(list[si], list[ei]);

    int mid = (si + ei) / 2;
    ListNode *a = mergeKLists_(list, si, mid);
    ListNode *b = mergeKLists_(list, mid + 1, ei);

    return mergeLists(a, b);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;
    return mergeKLists_(lists, 0, lists.size() - 1);
}

// 23. ==================================================
//* using priority_queue ================================

struct compare
{
    bool operator()(const ListNode *a, const ListNode *b) const
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;
    for (ListNode *l : lists)
    {
        if (l != nullptr)
            pq.push(l);
    }

    if (pq.empty())
        return nullptr;

    ListNode *head = new ListNode(0);
    ListNode *curr = head;

    while (!pq.empty())
    {
        ListNode *l = pq.top();
        pq.pop();

        curr->next = l;
        curr = curr->next;

        if (l->next != NULL)
            pq.push(l->next);
    }
    return head->next;
}

// 1290. =================================================

ListNode *reverseList(ListNode *head)
{
    ListNode *forw = nullptr;
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        forw = curr->next;

        curr->next = prev;

        prev = curr;
        curr = forw;
    }
    return prev;
}

int getDecimalValue(ListNode *head)
{
    ListNode *nhead = reverseList(head);

    int ans = 0;
    int mult = 1;
    while (nhead != nullptr)
    {
        ans += mult * nhead->val;
        nhead = nhead->next;
        mult *= 2;
    }
    return ans;
}

// 143. =====================================================

ListNode *midValue(ListNode *head)
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

ListNode *reverseList(ListNode *head)
{
    ListNode *forw = nullptr;
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        forw = curr->next;

        curr->next = prev;

        prev = curr;
        curr = forw;
    }
    return prev;
}

void reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode *mid = midValue(head);
    ListNode *nhead = mid->next;
    mid->next = nullptr;

    nhead = reverseList(nhead);

    ListNode *curr1 = head;
    ListNode *curr2 = nhead;

    ListNode *forw1 = nullptr;
    ListNode *forw2 = nullptr;

    while (curr1 != nullptr && curr2 != nullptr)
    {
        forw1 = curr1->next;
        forw2 = curr2->next;

        curr1->next = curr2;
        curr2->next = forw1;

        curr1 = forw1;
        curr2 = forw2;
    }
}

void againReorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode *c1 = head;

    ListNode *nhead = head->next;
    ListNode *c2 = head->next;

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c2->next != nullptr)
        {
            c1->next = c2->next;
            c1 = c1->next;
        }
        else
            break;

        if (c1->next != nullptr)
        {
            c2->next = c1->next;
            c2 = c2->next;
        }
        else
            break;
    }

    c1->next = nullptr;
    c2->next = nullptr;

    nhead = reverseList(nhead);
    c1->next = nhead;
    nhead = reverseList(nhead);
}