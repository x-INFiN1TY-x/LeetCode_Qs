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
        
        // Find the position to break the list
        temp = head;
        for (int i = 0; i < c - k - 1; ++i) {
            temp = temp->next;
        }
        
        // Adjust pointers to rotate the list
        ListNode* new_head = temp->next;
        temp->next = nullptr; // Cut off the list to form new tail
        
        // Connect the original tail to the original head to form circular
        temp = new_head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head;
        
        return new_head;
    }
};
