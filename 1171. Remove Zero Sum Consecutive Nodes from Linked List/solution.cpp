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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a dummy head node to handle edge cases seamlessly
        ListNode* dummyHead = new ListNode(0, head);
        unordered_map<int, ListNode*> lastSeenPrefixSum;
        ListNode* current = dummyHead;
        int prefixSum = 0;

        // First pass to record the last occurrence of each prefix sum
        while (current) {
            prefixSum += current->val;
            lastSeenPrefixSum[prefixSum] = current;
            current = current->next;
        }

        // Reset the prefix sum and re-iterate from the dummy head
        prefixSum = 0;
        current = dummyHead;

        // Second pass to connect nodes bypassing the zero-sum sublists
        while (current) {
            prefixSum += current->val;
            // Link the current node to the node following the last occurrence of the same prefix sum
            // This effectively removes the zero-sum sublists
            current->next = lastSeenPrefixSum[prefixSum]->next;
            current = current->next;
        }

        // Return the next element of the dummy head which would be the new list head
        return dummyHead->next;
    }
};

/* 
Approach:
    This solution works by first creating a dummy head node to simplify edge cases where the head itself might be part of a zero-sum sequence. It then uses a hash table 
    (lastSeenPrefixSum) to record the last occurrence of each prefix sum encountered during the first pass through the linked list. In the second pass, it updates the next pointers of 
    nodes to bypass any zero-sum sublists, effectively removing them from the list. Finally, it returns the new head of the list, which is the next node after the dummy head.

        The approach involves using a two-pass method with a hash table to efficiently identify and remove sequences of nodes that sum to zero. Here's a summary of the approach:

        First Pass: Iterate through the linked list to calculate the prefix sum for each node. As you traverse the list, update a hash table (lastSeenPrefixSum) with the current node for each unique prefix sum encountered. This step allows you to keep track of the last occurrence of each prefix sum.

        Second Pass: Iterate through the list again, this time using the hash table to skip over nodes that are part of a zero-sum sublist. For each node, calculate the prefix sum and update the next pointer of the current node to point to the next node of the last occurrence of the current prefix sum in the hash table. This effectively removes the zero-sum sublists by bypassing them.

        Return the New Head: After removing the zero-sum sublists, return the next node after the dummy head, which is the new head of the modified linked list.

Complexity Analysis:
    Time Complexity: The time complexity of this solution is O(n), where n is the length of the linked list. This is because the solution involves two separate passes through 
    the linked list, each of which takes O(n) time.

    Space Complexity: The space complexity is also O(n). The primary factor contributing to this complexity is the hash table (lastSeenPrefixSum), which stores a value for each unique 
    cumulative sum encountered while iterating through the list. In the worst-case scenario, there could be as many unique sums as there are nodes in the list, requiring O(n) space.

 */