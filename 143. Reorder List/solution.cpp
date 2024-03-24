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

#include <iostream>

using namespace std;

class Solution {
public:
    // Function to reorder a linked list
    void reorderList(ListNode* head) {
        // If head is null or there's only one node, no reordering needed
        if (!head || !head->next)
            return;

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* newNode = reverseList(slow->next);
        slow->next = nullptr;

        // Merge both halves of the list
        ListNode* curr = head;
        ListNode* dummy = newNode;
        while (curr && dummy) {
            ListNode* temp = curr->next;
            curr->next = dummy;
            ListNode* temp2 = dummy->next;
            dummy->next = temp;
            curr = temp;
            dummy = temp2;
        }
    }

    // Function to reverse a linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

/* 
Approach Summary

    The solution uses a two-pointer technique to find the middle of the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle.
    The second half of the list is then reversed by iterating through it and updating the next pointers of each node to point to the previous node.
    Finally, the first half and the reversed second half of the list are merged in an alternating manner by iterating through both halves simultaneously and adjusting the next pointers of the nodes accordingly.

Complexity Analysis

    Time Complexity: The time complexity is O(n), where n is the number of nodes in the list. This is because each node in the list is visited at most twice: once by the slow pointer to find the middle, and once by the reversed second half to merge with the first half.
    
    Space Complexity: The space complexity is O(1), as the solution only uses a constant amount of space to store the pointers and does not depend on the size of the input list.
 */
