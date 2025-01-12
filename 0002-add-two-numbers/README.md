# Description

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
![Image](./addtwonumber1.jpg)
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

Example 2:
```
Input: l1 = [0], l2 = [0]
Output: [0]
```

Example 3:
```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

# Solution 1: Simple Traversal

The solution to this problem is simple. Just simply traverse through the linked lists until both l1 and l2 are NULL and there is no remaining carry.

For each digit, allocate memory to a new linked list node and initialize the sum to 0. If there is a remaining carry, add that carry to the sum. If l1 is valid, add the node's value to the digit sum. If l2 is valid, add the node's value to the digit sum. 

If sum is greater than 9, have the carry equal to the second digit and have the sum equal to the sum that is modulo divded by 10.

Have the new node equal to the sum and insert the new node at the tail of the resulting linked list.

**The time complexity of this solution is `O(n).`**