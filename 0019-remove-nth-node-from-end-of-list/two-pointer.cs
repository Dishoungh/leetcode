/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public ListNode RemoveNthFromEnd(ListNode head, int n)
    {
        // Create ne wnode to potentially replace the head
        ListNode tmp = new ListNode(0, head);

        // Create two pointers
        ListNode left  = tmp;
        ListNode right = tmp;

        // Move right pointer N steps ahead of left
        for (int i = 0; i < n; i++)
        {
            right = right.next;
        }

        // Move both left and right until right reaches the end
        while (right.next != null)
        {
            left  = left.next;
            right = right.next;
        }

        // Replace the node right after left
        left.next = (left.next).next;

        // It's possible that the original head may be removed
        ListNode res = tmp.next;
        return res;
    }
}