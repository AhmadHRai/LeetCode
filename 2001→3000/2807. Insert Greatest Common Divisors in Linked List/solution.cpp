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
    // Function to compute the greatest common divisor (GCD) of two integers
    int GCD(int a, int b) {
        int minimum = min(a, b); // Find the smaller of the two numbers
        for (int i = minimum; i >= 1; i--) {
            if (a % i == 0 && b % i == 0) return i; // Return the largest number that divides both
        }
        return 1; // Return 1 if no other common divisor is found
    }

    // Function to insert a new node with the greatest common divisor (GCD) between consecutive nodes
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == NULL) return head; // If the list has only one node, return it as is

        ListNode* ans = head; // The head of the modified list

        while (head->next) {
            int x = GCD(head->val, head->next->val); // Compute the GCD of the current node and the next node
            ListNode* temp = new ListNode(x); // Create a new node with the GCD value
            temp->next = head->next; // Insert the new node between the current node and the next node
            head->next = temp;
            head = temp->next; // Move to the next pair of nodes
        }

        return ans; // Return the head of the modified list
    }
};

/*
Approach Summary:
- The `insertGreatestCommonDivisors` function modifies a singly linked list by inserting a new node with the greatest common divisor (GCD) between each pair of consecutive nodes.
- The `GCD` function computes the GCD of two integers using a straightforward approach.
- For each pair of consecutive nodes in the list, the function inserts a new node with the computed GCD value between them.

Time Complexity:
- O(n * min(a, b)), where n is the number of nodes in the list, and `a` and `b` are the values of the nodes. The GCD computation is done for each pair of nodes.

Space Complexity:
- O(n), where n is the number of nodes in the list. The space is used to store the new nodes that are inserted into the list.
*/
