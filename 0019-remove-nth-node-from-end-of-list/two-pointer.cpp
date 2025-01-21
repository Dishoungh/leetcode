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
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            // Create ne wnode to potentially replace the head
            ListNode* tmp = new ListNode(0, head);

            // Create two pointers
            ListNode* left  = tmp;
            ListNode* right = tmp;

            // Move right pointer N steps ahead of left
            for (int i = 0; i < n; i++)
            {
                right = right->next;
            }

            // Move both left and right until right reaches the end
            while (right->next)
            {
                left  = left->next;
                right = right->next;
            }

            // Replace the node right after left (left->next = left->next->next)
            left->next = left->next->next;

            // It's possible that the original head may be removed
            ListNode* res = tmp->next;
            delete tmp;
            return res;
        }
};