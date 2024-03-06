class Solution {
public:
    // Function to find the node at which the cycle begins.
    // If there is no cycle, it returns NULL.
    ListNode *floydcycle(ListNode *head) {
        if(head==NULL) { // If the head is NULL, the list is empty, so no cycle.
            return NULL;
        }

        ListNode *slow=head; // Initialize slow pointer to the head of the list.
        ListNode *fast=head; // Initialize fast pointer to the head of the list.
      
        // Loop until either slow or fast pointer reaches the end of the list.
        while(slow!=NULL && fast!=NULL) {
            fast=fast->next; // Move fast pointer one step forward.
            if(fast!=NULL) // Check if fast pointer is not at the end of the list.
                fast=fast->next; // Move fast pointer one more step forward.
            slow=slow->next; // Move slow pointer one step forward.
            if(slow==fast) // If slow and fast pointers meet, a cycle is detected.
                return slow; // Return the node at which the cycle begins.
        }
        return NULL; // If no cycle is detected, return NULL.
    }
    // Function to check if a cycle exists in the list.
    bool hasCycle(ListNode *head) {
        return floydcycle(head); // If floydcycle returns a non-NULL value, a cycle exists.
    }
};

/* 
Approach:

    The algorithm uses two pointers, slow and fast, to traverse the linked list. The slow pointer moves one node at a time, while the fast pointer moves two nodes at a time.
    If there is a cycle, the fast pointer will eventually catch up to the slow pointer within the cycle. If there is no cycle, the fast pointer will reach the end of the list (NULL).
    By comparing the nodes pointed to by slow and fast, the algorithm can determine if a cycle exists.

Complexity Analysis:

    Time Complexity: O(n), where n is the number of nodes in the linked list. This is because in the worst case, both pointers traverse the entire list.
    Space Complexity: O(1), as the algorithm uses a constant amount of space to store the two pointers.

 */