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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are enough nodes to reverse.
        ListNode* cursor = head;
        for (int i = 0; i < k; i++) {
            // If there are fewer than k nodes, no reversal is done, return the current head
            if (cursor == nullptr) return head;
            cursor = cursor->next;
        }

        // Step 2: Reverse the first k nodes
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for (int i = 0; i < k; i++) {
            nxt = curr->next;   // Save the next node
            curr->next = prev;  // Reverse the current node's pointer
            prev = curr;        // Move prev and curr one step forward
            curr = nxt;
        }

        // Step 3: After reversing the first k nodes, the original head node should be linked to the result of reversing the remaining list
        head->next = reverseKGroup(curr, k);
        
        // Step 4: Return the new head of the reversed segment
        return prev;
    }
};

/**
 * Approach Summary:
 * - This problem involves reversing nodes in k-group segments in a singly linked list.
 * - The function first checks if there are enough nodes (k nodes) available to reverse. If not, it returns the head as is.
 * - If there are enough nodes, it reverses the first k nodes using a three-pointer technique (prev, curr, and next).
 * - After reversing the first k nodes, it recursively calls the function on the rest of the list, starting from the node right after the reversed group.
 * - The key idea is to reverse k nodes at a time and then link the last node of the reversed group with the result of the subsequent recursive call.
 *
 * Time Complexity:
 * - The function processes each node exactly once during the reversal process, so the time complexity is O(n), where n is the number of nodes in the list.
 * - The recursion will break the list into k-sized chunks, and each chunk will be reversed in linear time.
 *
 * Space Complexity:
 * - The space complexity is O(n) because of the recursive call stack. In the worst case, if the entire list is reversed, the recursion depth is O(n/k), resulting in O(n) space usage for the call stack.
 * - No extra space is used outside of the recursion and pointer manipulation.
 */
