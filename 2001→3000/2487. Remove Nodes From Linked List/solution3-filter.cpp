/* 
Intuition:

    We can reverse the given linked list first. Then we traverse the reversed list, keeping nodes whose values are greater than or equal to the previous node's value. After traversing, we reverse the resulting list to obtain the modified linked list.

Approach:

    1. Reverse the given linked list.
    2. Initialize a dummy node to hold the result.
    3. Traverse the reversed list, keeping nodes whose values are greater than or equal to the previous node's value.
    4. Reverse the resulting list to obtain the modified linked list.
    5. Return the head of the modified linked list.

Complexity:

    Time complexity: O(n), where n is the number of nodes in the linked list.
     Space complexity: O(1), as no extra space is used apart from a few pointers.

 */

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;

        while (curr != nullptr) {
            // ListNode* next = curr->next;
            // curr->next = prev;
            // prev = curr;
            // curr = next;
            swap(curr->next, prev);
            swap(prev, curr);
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* tempPrev = dummyHead;
        curr = prev;

        while (curr != nullptr) {
            if (curr->val >= tempPrev->val) {
                tempPrev->next = curr;
                tempPrev = curr;
                curr = curr->next;
                tempPrev->next = nullptr;
            } else {
                curr = curr->next;
            }
        }

        ListNode *newPrev = nullptr, *newCurr = dummyHead->next;
        while (newCurr != nullptr) {
            // ListNode* next = newCurr->next;
            // newCurr->next = newPrev;
            // newPrev = newCurr;
            // newCurr = next;
            swap(newCurr->next, newPrev);
            swap(newPrev, newCurr);
        }

        return newPrev;
    }
};