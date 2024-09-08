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
    // Function to split the linked list into k parts with approximately equal sizes
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Create a vector of ListNode pointers to store the k parts.
        vector<ListNode*> parts(k, nullptr);

        // Calculate the length of the linked list.
        int len = 0;
        for (ListNode* node = head; node; node = node->next)
            len++;

        // Calculate the minimum guaranteed part size (n) and the number of extra nodes (r).
        int n = len / k, r = len % k;

        // Initialize pointers to traverse the linked list.
        ListNode* node = head;
        ListNode* prev = nullptr;

        // Loop through each part.
        for (int i = 0; node && i < k; i++, r--) {
            // Store the current node as the start of the current part.
            parts[i] = node;
            // Traverse n + 1 nodes if there are remaining extra nodes (r > 0).
            // Otherwise, traverse only n nodes.
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            // Disconnect the current part from the rest of the list by setting prev->next to nullptr.
            if (prev) prev->next = nullptr;
        }

        // Return the array of k parts.
        return parts;
    }
};

/*
Approach Summary:
- The `splitListToParts` function splits the linked list into `k` parts with sizes as evenly distributed as possible.
- The length of the linked list is calculated first. Each part is then assigned nodes based on the minimum size `n` and any remaining nodes.
- The function uses two pointers, `node` to traverse the list and `prev` to adjust the end of each part.

Time Complexity:
- O(N), where N is the number of nodes in the linked list. Each node is visited exactly once to calculate the length and to split the list.

Space Complexity:
- O(k), where k is the number of parts. The space is used for the vector storing the head of each part.
*/
