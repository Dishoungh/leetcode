#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    // Create new node to potentially replace the head
    struct ListNode* tmp = (struct ListNode*) malloc(sizeof(struct ListNode));
    tmp->val = 0;
    tmp->next = head;

    // Create two pointers
    struct ListNode* left  = tmp;
    struct ListNode* right = tmp;

    // Move right pointer N steps ahead of left
    for (int i = 0; i < n; i++)
    {
        right = right->next;
    }

    // Move both left and right pointers until right reaches the end
    while (right->next)
    {
        left = left->next;
        right = right->next;
    }

    // Replace the node right after left (left->next = left->next->next)
    left->next = left->next->next;

    // It's possible that the original head may be removed. We must preserve this
    struct ListNode* res = tmp->next;
    free(tmp);
    return res;
}