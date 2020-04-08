
// 876. MERE WALA ========================================

class Solution {
    public ListNode middleNode(ListNode head) {
        if (head == null && head.next == null)
            return head;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}

// 876. SIR WALA =========================================

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return fast.next == null ? slow : slow.next;
    }
}

// 206. =================================================

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode forw = null;
        ListNode curr = head;

        while (curr != null) {
            forw = curr.next;// backup.

            curr.next = prev;// link join.

            prev = curr;// move forward.
            curr = forw;
        }
        return prev;
    }
}

// 234. ===========================================================

class Solution {

    public ListNode midbyIndex(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode forw = null;
        ListNode curr = head;

        while (curr != null) {
            forw = curr.next;

            curr.next = prev;

            prev = curr;
            curr = forw;
        }
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
            return true;

        ListNode mid = midbyIndex(head);
        ListNode nhead = mid.next;
        mid.next = null;

        nhead = reverseList(nhead);

        while (nhead != null && head != null) {
            if (nhead.val != head.val) {
                return false;
            }

            head = head.next;
            nhead = nhead.next;
        }
        return true;
    }
}