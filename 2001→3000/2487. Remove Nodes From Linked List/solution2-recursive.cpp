/* 
Intuition:

    We can use recursion to traverse the linked list and at each step, we compare the current node's value with the value of the next greater node. If the next greater node 
    has a value less than the current node, we keep the current node; otherwise, we skip the current node.

Approach:

    1. Recursively traverse the linked list.
    2. At each step, compare the current node's value with the value of the next greater node.
    3. If the next greater node has a value less than the current node, keep the current node; otherwise, skip the current node.
    4. Return the head of the modified linked list.

Complexity:

    Time complexity: O(n), where n is the number of nodes in the linked list.
    Space complexity: O(n), due to the recursive stack space.

 */

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* node = head;
        ListNode* nxtGreater = removeNodes(node->next);

        node->next = nxtGreater;
        if (nxtGreater == nullptr || node->val >= nxtGreater->val) {
            return node;
        }
        return nxtGreater;
    }
};