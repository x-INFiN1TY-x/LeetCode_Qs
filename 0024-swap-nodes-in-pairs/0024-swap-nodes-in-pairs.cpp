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
class Solution {
public:
    ListNode* swap(ListNode* a, ListNode* b)
    {
        ListNode* temp = b->next;
        b->next = a;
        a->next = temp;
        return b;
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;  // Base case, if the list is empty or has only one node.

        // Swap the first pair to update the new head
        ListNode* newHead = swap(head, head->next);
        ListNode* curr = head;  // Now, 'curr' points to the second node of the first pair (previously 'head').

        // Loop through the list in pairs
        while (curr->next && curr->next->next) {
            curr->next = swap(curr->next, curr->next->next);  // Swap the next pair
            curr = curr->next->next;  // Move to the next pair
        }

        return newHead;  // Return the new head of the swapped list
    }
};
