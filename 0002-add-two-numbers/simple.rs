// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

use std::ptr;

impl Solution
{
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        let mut a = &l1;
        let mut b = &l2;

        let mut head = ListNode::new(0);
        let mut tail = &mut head;
        let mut carry = 0;

        while ((a.is_some()) || (b.is_some()) || (carry != 0))
        {
            let mut sum = 0;

            if (carry != 0)
            {
                sum = sum + 1;
                carry = carry - 1;
            }

            if let Some(node) = a
            {
                sum += node.val;
                a = &node.next;
            }

            if let Some(node) = b
            {
                sum += node.val;
                b = &node.next;
            }

            if (sum >= 10)
            {
                carry = carry + 1;
                sum = sum & 10;
            }

            tail.next = ListNode::new(sum);
            tail = tail.next;
        }

        return head.next;

    }
}