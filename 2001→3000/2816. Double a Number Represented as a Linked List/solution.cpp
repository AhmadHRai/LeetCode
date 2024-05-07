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
    ListNode* doubleIt(ListNode* head) {
        // If the head node's value is greater than 4, prepend a new node with value 0
        if (head->val > 4)
            head = new ListNode(0, head);
        // Iterate through each node in the list
        for(ListNode* node = head; node; node = node->next) {
            // Double the value of the current node and take modulo 10 to keep the value within a single digit
            node->val = (node->val * 2) % 10;
            // If the next node exists and its value is greater than 4, increment the current node's value
            // to account for the carry from the next node
            if (node->next && node->next->val > 4)
                node->val++;
        }
        // Return the modified list
        return head;
    }
};

/* 
Intuition & Approach:

    The solution iterates through each node in the linked list, doubling the value of each node. If the value of the next node is greater than 4, it indicates that there 
    will be a carry from the next node, which is accounted for by incrementing the current node's value.

    1. If the head node's value is greater than 4, a new node with value 0 is prepended to the list. This is done to handle the case where the head node's value, when doubled, would result in a carry.
    2. For each node in the list, the value is doubled and modulo 10 is taken to ensure the value remains within a single digit.
    3. If the next node exists and its value is greater than 4, the current node's value is incremented by 1 to account for the carry from the next node.

Complexity:

    Time Complexity: O(n), where n is the number of nodes in the linked list. This is because the algorithm iterates through each node in the list once.
    Space Complexity: O(1), as the algorithm does not use any additional space that scales with the input size. It modifies the linked list in-place.

*/