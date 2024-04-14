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
public:
    int sum = 0; // Initialize the sum to 0.

    int sumOfLeftLeaves(TreeNode* root) {
        // Call the helper function to calculate the sum of left leaves.
        left(root);
        // Return the calculated sum.
        return sum;
    }
    
    void left(TreeNode* root) {
        // Base case: if the current node is null, return.
        if (root == nullptr) return;
        
        // Check if the current node's left child is a leaf node (i.e., it has no children).
        if (root->left && !root->left->left && !root->left->right) {
            // If it is, add its value to the sum.
            sum += root->left->val;
        }
        
        // Recursively call the function for the left and right children of the current node.
        left(root->left);
        left(root->right);
    }
};

/* 
Approach

    The solution uses a depth-first search (DFS) approach to traverse the binary tree. It defines a helper function `left` that checks if a node is a leaf node (i.e., it has no 
    children) and if it is a left child of its parent. If both conditions are met, it adds the value of the node to the sum. The function is then called recursively for the left and 
    right children of each node.

Complexity

    Time complexity: O(n), where n is the number of nodes in the tree. This is because each node in the tree is visited exactly once.
    
    Space complexity: O(h), where h is the height of the tree. This is due to the recursive call stack, which in the worst case can go as deep as the height of the tree.
 */
