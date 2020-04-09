
// 141. =======================================

public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                break;
        }

        return fast == slow;
    }
}

// 142 . =======================================

public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null)
            return null;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                break;
        }

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow.next;
                fast = fast.next;
            }
            return slow;
        }
        return null;
    }
}

// 160. ========================================

public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null)
            return null;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                break;
        }

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow.next;
                fast = fast.next;
            }
            return slow;
        }
        return null;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;
        if (headA.next == null && headB.next == null && headA.val == headB.val)
            return headA;

        ListNode curr = headA;
        ListNode tail = null;

        while (curr != null) {
            tail = curr;
            curr = curr.next;
        }

        tail.next = headB;
        ListNode ans = detectCycle(headA);
        tail.next = null;

        return ans;
    }
}

// 21. ================================================

class Solution {
    public ListNode mergeTwoLists(ListNode A, ListNode B) {
        if (A == null)
            return B;
        if (B == null)
            return A;

        ListNode head = new ListNode(0); // any value inside the head is not going to matter
        ListNode curr = head;

        while (A != null && B != null) {
            if (A.val <= B.val) {
                curr.next = A;
                A = A.next;
            }

            else {
                curr.next = B;
                B = B.next;
            }
            curr = curr.next;
        }

        if (A != null)
            curr.next = A;

        if (B != null)
            curr.next = B;

        return head.next;
    }
}

// 148. ========================================================
// * MERGE SORT , complexcity : O(nlog(n))

class Solution {
    public ListNode midByINDEX(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    public ListNode mergeList(ListNode a, ListNode b) {
        if (a == null) {
            return b;
        }

        if (b == null) {
            return a;
        }

        ListNode head = new ListNode(0);
        ListNode curr = head;

        while (a != null && b != null) {
            if (a.val <= b.val) {
                curr.next = a;
                a = a.next;
            } else {
                curr.next = b;
                b = b.next;
            }
            curr = curr.next;
        }

        if (a != null) {
            curr.next = a;
        }
        if (b != null) {
            curr.next = b;
        }

        return head.next;
    }

    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode mid = midByINDEX(head);
        ListNode nhead = mid.next;
        mid.next = null;

        ListNode a = sortList(head);
        ListNode b = sortList(nhead);

        return mergeList(a, b);
    }
}

// 23. ==================================================
// * using priority_queue ================================

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((ListNode a, ListNode b) -> {
            return a.val - b.val;
        });

        for (ListNode l : lists) {
            if (l != null)
                pq.add(l);
        }

        if (pq.isEmpty())
            return null;

        ListNode head = new ListNode(0);
        ListNode curr = head;

        while (!pq.isEmpty()) {
            ListNode l = pq.poll();

            curr.next = l;
            curr = curr.next;

            if (l.next != null)
                pq.add(l.next);
        }

        return head.next;
    }
}

// 1290. ==================================================

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;
        ListNode forw = null;

        while (curr != null) {
            forw = curr.next;

            curr.next = prev;

            prev = curr;
            curr = forw;
        }
        return prev;
    }

    public int getDecimalValue(ListNode head) {
        ListNode nhead = reverseList(head);

        int ans = 0;
        int mult = 1;
        while (nhead != null) {
            ans += mult * nhead.val;
            nhead = nhead.next;
            mult *= 2;
        }
        return ans;
    }
}

// 143. ========================================================

class Solution {
    public ListNode midValue(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public ListNode reverseList(ListNode head) {
        ListNode forw = null;
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            forw = curr.next;

            curr.next = prev;

            prev = curr;
            curr = forw;
        }
        return prev;
    }

    public void reorderList(ListNode head) {
        if (head == null || head.next == null)
            return;

        ListNode mid = midValue(head);
        ListNode nhead = mid.next;
        mid.next = null;

        nhead = reverseList(nhead);

        ListNode curr1 = head;
        ListNode curr2 = nhead;
        ListNode forw1 = null;
        ListNode forw2 = null;

        while (curr1 != null && curr2 != null) {
            forw1 = curr1.next;
            forw2 = curr2.next;

            curr1.next = curr2;
            curr2.next = forw1;

            curr1 = forw1;
            curr2 = forw2;
        }
    }

    void againReorderList(ListNode head) {
        if (head == null || head -> next == null)
            return;

        ListNode c1 = head;

        ListNode nhead = head.next;
        ListNode c2 = head.next;

        while (c1 != null && c2 != null) {
            if (c2.next != null) {
                c1.next = c2.next;
                c1 = c1.next;
            } else
                break;

            if (c1.next != null) {
                c2.next = c1.next;
                c2 = c2.next;
            } else
                break;
        }

        c1.next = null;
        c2.next = null;

        nhead = reverseList(nhead);
        c1.next = nhead;
        nhead = reverseList(nhead);
    }
}
