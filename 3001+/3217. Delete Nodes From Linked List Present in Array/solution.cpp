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
    // Function to modify the linked list by removing nodes with values in the given list
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> hasN = 0; // Bitset to track values that need to be removed
        
        // Mark values that need to be removed
        for (int x : nums) hasN[x] = 1;

        ListNode dummy(0, head); // Dummy node to simplify edge cases
        ListNode* prev = &dummy; // Pointer to the previous node
        ListNode* tmp = NULL;    // Temporary pointer for node deletion

        // Iterate through the linked list
        for (ListNode* curr = head; curr; curr = curr->next, delete tmp) {
            if (hasN[curr->val]) { // If current node's value is in the removal list
                prev->next = curr->next; // Skip the current node
                tmp = curr; // Mark node for deletion
            } else {
                prev = prev->next; // Move the previous pointer
                tmp = NULL; // No node to delete
            }
        }

        return dummy.next; // Return the modified list, skipping the dummy node
    }
};

/*
Approach Summary:
- Use a bitset to efficiently track which values should be removed from the linked list.
- Iterate through the linked list, adjusting pointers to skip nodes that have values in the removal list.
- Use a dummy node to handle edge cases where the head of the list might change.

Time Complexity:
- O(m + n), where m is the number of nodes in the linked list and n is the number of elements in the `nums` vector. The function processes each node and each value in the `nums` vector.

Space Complexity:
- O(n), where n is the number of elements in the `nums` vector. The space is used by the bitset to track values to be removed.
*/
