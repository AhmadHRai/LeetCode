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

class Solution 
{
public:
    // Function to reverse the portion of the linked list between 'first' and 'last'
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;  // Initialize previous node as 'last' (the node after the last one to be reversed)
        
        // Reverse the list between 'first' and 'last' nodes (exclusive)
        while (first != last)
        {
            auto tmp = first->next;  // Save the next node
            first->next = prev;      // Reverse the link by making current node point to 'prev'
            prev = first;            // Move 'prev' to the current node
            first = tmp;             // Move to the next node in the list
        }
        
        return prev;  // Return the new head of the reversed portion
    }
    
    // Function to reverse nodes in k-sized groups
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        auto node = head;
        
        // Check if there are enough nodes to form a group of k
        for (int i = 0; i < k; ++i)
        {
            if (!node)  // If there are fewer than k nodes, no reversal is done
                return head;  // Return the head without changes
            node = node->next;
        }

        // Reverse the first k nodes and connect them to the result of the next group
        auto new_head = reverse(head, node);  // Reverse the first k nodes
        head->next = reverseKGroup(node, k);  // Recursively reverse the remaining list
        
        return new_head;  // Return the new head of the reversed k-group
    }
};

/**
 * Approach Summary:
 * - The `reverseKGroup` function aims to reverse nodes in k-sized groups in a singly linked list.
 * - First, we check if there are enough nodes (k nodes) in the current group. If not, we return the current head without any changes.
 * - If there are enough nodes, we call the `reverse` function to reverse the nodes between `head` and `node` (which points to the node after the k-th node).
 * - After reversing the first k nodes, we recursively call `reverseKGroup` for the rest of the list (starting from the node after the reversed portion).
 * - The key idea is that the reversal is done in chunks of k, and the nodes are connected recursively after reversing each group.
 * 
 * Time Complexity:
 * - The time complexity is O(n), where n is the number of nodes in the linked list. Each node is processed once during the reversal operation.
 * - The recursive calls will process the nodes in chunks of size k, but each node is reversed exactly once, resulting in O(n) overall time complexity.

 * Space Complexity:
 * - The space complexity is O(1) because no extra data structures are used (we only use pointers to traverse and reverse the list).
 * - However, since this is a recursive solution, the space complexity due to the call stack is O(n/k), which is at most O(n) in the worst case.
 */
