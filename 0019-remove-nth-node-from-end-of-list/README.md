# Description

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

![Image](./linkedlist.jpg)

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

Example 2:
```
Input: head = [1], n = 1
Output: []
```

Example 3:
```
Input: head = [1,2], n = 1
Output: [1]
```

Constraints:
- The number of nodes in the list is sz.
- 1 <= sz <= 30
- 0 <= Node.val <= 100
- 1 <= n <= sz


# Two Pointer Method

This algorithm is pretty simple. We will keep track of two pointers `left` and `right`. To delete the Nth node, advance the right pointer N times from the left pointer. At this point, the distance between the left and right pointers is N. Now, all we have to do is continue moving the left and right pointers until `right->next` is NULL. To remove the node, simply place the left->next pointer as left->next->next.

As an edge case, there may be scenarios where the head will need to be removed. To not destroy the entire Linked List, we create a temporary node to preserve the linked list in case the head needs to be removed.

**The time complexity of this algorithm is `O(N)`.**