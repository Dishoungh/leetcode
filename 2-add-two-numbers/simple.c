/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdint.h>
#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    uint8_t carry = 0;

    while (l1 || l2 || carry)
    {
        struct ListNode* tmp = (struct ListNode*) malloc(sizeof(struct ListNode));
        uint8_t sum = 0;

        if (carry)
        {
            sum++;
            carry--;
        }

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        if (sum >= 10)
        {
            carry++;
            sum   = sum % 10;
        }

        tmp->val  = sum;
        tmp->next = NULL;

        if (!head)
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }

    return head;
}