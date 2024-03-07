class Solution {
public:
    // Function to find the middle node of the linked list.
    // If the list has an even number of nodes, it returns the second middle node.
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; // Initialize slow pointer to the head of the list.
        ListNode* fast = head; // Initialize fast pointer to the head of the list.
        // Loop until the fast pointer reaches the end of the list or the next node is NULL.
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next; // Move the slow pointer one step forward.
            fast = fast->next->next; // Move the fast pointer two steps forward.
        }
        // When the loop ends, the slow pointer is at the middle of the list.
        return slow; // Return the middle node.
    }
};

/* 
Approach:

    The algorithm uses two pointers, slow and fast, to traverse the linked list. The slow pointer moves one node at a time, while the fast pointer moves two nodes at a time.
    By the time the fast pointer reaches the end of the list or its next node is NULL, the slow pointer will be at the middle of the list.
    If the list has an even number of nodes, the slow pointer will be at the second middle node, which is the correct solution as per the problem statement.

Complexity Analysis:

    Time Complexity: O(n), where n is the number of nodes in the linked list. This is because in the worst case, both pointers traverse the entire list.
    Space Complexity: O(1), as the algorithm uses a constant amount of space to store the two pointers.

 */