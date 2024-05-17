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
 * 
 * This struct represents a node in a binary tree. Each node contains:
 * - An integer value `val`.
 * - Pointers to the left and right children (`left` and `right`).
 */

class Solution {
public:
    /**
     * This function removes all leaf nodes from the binary tree that have a specified target value.
     * It uses a post-order traversal to ensure that it checks and removes leaf nodes from the bottom up.
     * 
     * The function recursively processes the left and right children of the current node.
     * If a node becomes a leaf node with the target value after its children are processed, it is removed.
     * 
     * @param r A pointer to the root node of the binary tree.
     * @param target The target value of the leaf nodes to be removed.
     * @return A pointer to the root node of the modified tree.
     */
    TreeNode* removeLeafNodes(TreeNode* r, int target) {
        if (r == nullptr) return nullptr; // Base case: if the current node is null, return null
        r->left = removeLeafNodes(r->left, target); // Recursively process the left child
        r->right = removeLeafNodes(r->right, target); // Recursively process the right child
        // If the current node becomes a leaf node with the target value, remove it by returning null
        return (r->left == nullptr && r->right == nullptr && r->val == target) ? nullptr : r;
    }
};

/* 
Explanation

In this C++ code:

    The TreeNode struct defines the structure of a binary tree node, which includes an integer value val and pointers to the left and right children.
    The Solution class contains the removeLeafNodes method, which removes all leaf nodes with a specified target value from the binary tree.
    The method uses a post-order traversal (processing the children before the parent node) to ensure that it correctly identifies and removes leaf nodes from the bottom up.
    The base case for the recursion is when the current node is nullptr, in which case it returns nullptr.
    After recursively processing the left and right children, the method checks if the current node has become a leaf node with the target value. If so, it returns nullptr to remove the node; otherwise, it returns the current node.

Complexity Analysis

    Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once.
    Space Complexity: O(h), where h is the height of the binary tree. This is due to the recursion stack.
 */