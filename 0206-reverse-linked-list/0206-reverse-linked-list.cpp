class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        
        while (curr != NULL) {
            fwd = curr->next;   // Store the next node
            curr->next = prev;  // Reverse the current node's pointer
            prev = curr;        // Move prev and curr pointers one step forward
            curr = fwd;
        }
        
        return prev;  // Return the new head of the reversed list
    }
};
