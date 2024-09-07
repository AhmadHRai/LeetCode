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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Helper function to check if the linked list starting from `head` matches a path in the binary tree rooted at `root`
    bool check(ListNode *head, TreeNode* root) {
        if (!root) return false; // Base case: if the binary tree node is null, return false
        if (head->val != root->val) return false; // Current node values do not match
        
        if (head->next == NULL) return true; // Reached the end of the linked list successfully
        
        bool left = false;
        bool right = false;
        
        // Check if the next node in the linked list matches the left child of the binary tree node
        if (root->left && head->next && root->left->val == head->next->val) {
            left = check(head->next, root->left);
        }
        
        // Check if the next node in the linked list matches the right child of the binary tree node
        if (root->right && head->next && root->right->val == head->next->val) {
            right = check(head->next, root->right);
        }
        
        return left || right; // Return true if either left or right subtree matches
    }

public:
    // Function to check if there is a path in the binary tree that matches the linked list `head`
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false; // Base case: if the binary tree is null, return false
        
        // Check if the current binary tree node matches the start of the linked list
        if (root->val == head->val) {
            if (check(head, root)) return true; // If the linked list matches, return true
        }
        
        // Recursively check both left and right subtrees of the binary tree
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

/*
Approach Summary:
- The `isSubPath` function checks if there is a path in the binary tree such that the values of the nodes along the path match the values of the linked list `head`.
- The helper function `check` verifies if the linked list starting from `head` can match a path in the binary tree starting from `root`.
- The function performs a depth-first search (DFS) to explore all possible paths in the binary tree.

Time Complexity:
- O(N * M), where N is the number of nodes in the binary tree and M is the length of the linked list. In the worst case, each node in the tree is compared with each node in the linked list.

Space Complexity:
- O(H), where H is the height of the binary tree. The space is used for the recursion stack during the DFS traversal.
*/
