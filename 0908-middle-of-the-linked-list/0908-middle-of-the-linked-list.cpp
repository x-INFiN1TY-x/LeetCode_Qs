class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head || !head->next) return head; // If head is null or there's only one node

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;      // Move slow by 1 step
            fast = fast->next->next;// Move fast by 2 steps
        }

        return slow;
    }
};
