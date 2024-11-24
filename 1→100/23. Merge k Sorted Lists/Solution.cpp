class Solution {
public:
    // Helper function to merge two sorted linked lists
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        // If the first list is empty, return the second list
        if (NULL == l1) return l2;
        // If the second list is empty, return the first list
        else if (NULL == l2) return l1;
        
        // If the value of the first list node is less than or equal to the second, recursively merge the rest of the first list with the second list
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        // If the value of the second list node is smaller, recursively merge the first list with the rest of the second list
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    
    // Main function to merge k sorted linked lists
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // If the list of lists is empty, return NULL
        if (lists.empty()) return NULL;
        
        int len = lists.size(); // Get the size of the lists vector
        // While there is more than one list to merge, keep merging them in pairs
        while (len > 1) {
            // Merge pairs of lists and store the result in the first half of the vector
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            // Update the length to be the number of merged lists
            len = (len + 1) / 2;
        }
        
        // Return the merged list, which is now stored in the first position of the vector
        return lists.front();
    }
};

/*
Approach Summary:
- The solution uses a divide-and-conquer approach to merge multiple sorted linked lists.
- The `mergeKLists` function iteratively merges the lists in pairs using the `mergeTwoLists` helper function.
- The merging process is done in a manner similar to the merge step in merge sort, where two lists are merged at a time.
- This continues until only one list remains, which is the merged result of all input lists.

Complexity Analysis:
- Time Complexity: O(N * log K), where N is the total number of nodes in all the lists and K is the number of lists.
  - Each merge operation takes O(N) time, and we perform log K levels of merging.
- Space Complexity: O(1) (ignoring the recursion stack), as we only need constant extra space to store the merged result and the recursive calls, with no additional data structures used.
*/
