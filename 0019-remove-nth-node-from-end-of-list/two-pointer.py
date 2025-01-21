# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Create a new node to potentially replace head
        tmp = ListNode(0, head)

        # Create two pointers
        left  = tmp
        right = tmp

        # Move right pointer N steps ahead of left
        for i in range(n):
            right = right.next
        
        # Move both left and right until right reaches the end
        while right.next is not None:
            left  = left.next
            right = right.next
        
        # Replace the node after left
        left.next = (left.next).next

        # It's possible that the original head may be removed
        return tmp.next
        