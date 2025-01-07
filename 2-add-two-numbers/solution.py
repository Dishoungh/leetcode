# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = tail = ListNode()
        carry = 0

        while ((l1 is not None) or (l2 is not None) or (carry != 0)):
            sum = 0

            if (carry != 0):
                sum = sum + 1
                carry = carry - 1
            
            if l1:
                sum += l1.val
                l1 = l1.next

            if l2:
                sum += l2.val
                l2 = l2.next

            if (sum >= 10):
                carry = carry + 1
                sum = sum % 10
            
            tail.next = ListNode(sum)
            tail = tail.next

        return head.next
        