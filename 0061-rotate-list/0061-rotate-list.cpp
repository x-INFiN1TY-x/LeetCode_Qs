class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head; // No rotation needed
        }
        
        ListNode* temp = head;
        int c = 1; // Initialize c to 1 since head is not nullptr
        
        // Count the number of nodes in the list
        while (temp->next != nullptr) {
            temp = temp->next;
            c++;
        }
        
        k = k % c; // Reduce unnecessary rotations
        
        if (k == 0) {
            return head; // No rotation needed after reducing k
        }
        
        // Find the new head and new tail positions
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move fast pointer to the kth node from the beginning
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Adjust pointers to rotate the list
        fast->next = head; // Connect original tail to original head to form circular
        head = slow->next; // New head is the node after slow
        slow->next = nullptr; // Cut off the list to form new tail
        
        return head;
    }
};
