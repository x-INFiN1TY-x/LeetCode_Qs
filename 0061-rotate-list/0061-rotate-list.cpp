class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head; // No rotation needed
        }

        ListNode* temp = head;
        int length = 1; // Length of the list
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }
        
        k = k % length; // Reduce unnecessary rotations
        
        if (k == 0) {
            return head; // No rotation needed after reducing k
        }

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
        ListNode* new_head = slow->next;
        slow->next = nullptr; // Cut off the list to form new tail
        fast->next = head; // Connect original tail to original head to form circular

        return new_head;
    }
};
