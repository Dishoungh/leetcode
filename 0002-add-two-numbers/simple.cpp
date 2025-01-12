/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            ListNode* head = NULL;
            ListNode* tail = NULL;
            uint8_t carry = 0;

            while (l1 || l2 || carry)
            {
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

                if (!head)
                {
                    head = tail = new ListNode(sum);
                }
                else
                {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                }
            }

            return head;
        }
};