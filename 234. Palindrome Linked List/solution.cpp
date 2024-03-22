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
    bool isPalindrome(ListNode* head) {
        // Initialize two pointers, slow and fast, to the head of the list.
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Use the fast pointer to find the middle of the list.
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Initialize pointers for reversing the second half of the list.
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        ListNode* curr = slow;
        
        // Reverse the second half of the list.
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // Compare the first half and the reversed second half to check for palindrome.
        while(prev && head){
            if(prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        
        // If the loop completes without returning false, the list is a palindrome.
        return true;
    }
};

/* 
Approach Summary

    The solution uses a two-pointer technique to find the middle of the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle.
    The second half of the list is then reversed by iterating through it and updating the next pointers of each node to point to the previous node.
    Finally, the first half and the reversed second half of the list are compared to check if they are identical, which would indicate that the list is a palindrome.

Complexity Analysis

    Time Complexity: The time complexity is O(n), where n is the number of nodes in the list. This is because each node is visited at most twice: once by the slow pointer to find the middle, and once by the reversed second half to compare with the first half.
    
    Space Complexity: The space complexity is O(1), as the solution only uses a constant amount of space to store the pointers and does not depend on the size of the input list.
 */
