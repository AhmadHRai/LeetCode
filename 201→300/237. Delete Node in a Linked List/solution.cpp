/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Store the node to be deleted in a temporary variable
        ListNode *temp = node->next;
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        // Update the next pointer of the current node to skip the next node
        node->next = node->next->next;
        // Delete the node that was originally next to the current node (to free memory from leak)
        delete temp;
    }
};

/* 
Approach:

    This solution directly modifies the linked list to delete a given node. It does so by copying the value of the next node to the current node and then updating the 
    next pointer of the current node to skip the next node. This effectively removes the next node from the list. The original next node is then deleted to prevent 
    memory leaks.

Complexity:

    Time Complexity: O(1), as the operation involves a constant number of steps regardless of the size of the list.
    Space Complexity: O(1), as the algorithm does not use any additional space that scales with the input size.

This approach is efficient for solving the problem within the given constraints, as it directly modifies the linked list to remove the specified node without the need for additional space.
*/