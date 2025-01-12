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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode head = null;
        ListNode tail = null;
        int carry = 0;

        while ((l1 != null) || (l2 != null) || (carry != 0))
        {
            int sum = 0;

            if (carry != 0)
            {
                sum++;
                carry--;
            }

            if (l1 != null)
            {
                sum += l1.val;
                l1 = l1.next;
            }

            if (l2 != null)
            {
                sum += l2.val;
                l2 = l2.next;
            }

            if (sum >= 10)
            {
                carry++;
                sum   = sum % 10;
            }

            if (head == null)
            {
                head = tail = new ListNode(sum);
            }
            else
            {
                tail.next = new ListNode(sum);
                tail = tail.next;
            }
        }

        return head;
    }
}