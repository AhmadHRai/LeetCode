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
    ListNode* reverseList(ListNode* head) {
        // Initialize two pointers: nextNode to keep track of the next node in the original list,
        // and prevNode to keep track of the previous node in the reversed list.
        ListNode *nextNode, *prevNode = NULL;
        // Iterate through the list until the head is NULL, which indicates the end of the list.
        while (head) {
            // Store the next node of the current node in nextNode.
            nextNode = head->next;
            // Reverse the next pointer of the current node to point to the previous node.
            head->next = prevNode;
            // Move prevNode one step forward to the current node.
            prevNode = head;
            // Move head one step forward to the next node in the original list.
            head = nextNode;
        }
        // Return the new head of the reversed list, which is the last node of the original list.
        return prevNode;
    }
};

/* 
Approach:
    The approach used here is an iterative method to reverse a linked list. It involves three pointers: head to traverse the list, nextNode to keep track of the next node in the 
    original list, and prevNode to keep track of the previous node in the reversed list. The algorithm iterates through the list, reversing the next pointer of each node to point to 
    the previous node, and updating the prevNode and head pointers accordingly.

Complexity:
    Time Complexity: The time complexity of this algorithm is O(N), where N is the number of nodes in the list. This is because each node in the list is visited exactly once during the iteration.

    Space Complexity: The space complexity is O(1), which means the space required does not grow with the size of the input list. This is because only a fixed number of pointers (nextNode and prevNode) are used, and their space requirements do not depend on the size of the list.
 */