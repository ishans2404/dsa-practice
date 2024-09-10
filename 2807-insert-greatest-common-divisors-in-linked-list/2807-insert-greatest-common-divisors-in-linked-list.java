/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int gcd(int a, int b) {
        if(a == 0) return b;
        return gcd(b % a, a);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode curr = head, after = head.next;

        while(curr != null && after != null) {
            ListNode tmp = new ListNode(gcd(curr.val, after.val));
            curr.next = tmp;
            tmp.next = after;
            curr = tmp.next;
            after = after.next;
        }
        return head;
    }
}