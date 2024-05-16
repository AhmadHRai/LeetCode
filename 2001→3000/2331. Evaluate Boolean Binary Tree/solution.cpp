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
     * This function evaluates a binary tree where:
     * - Leaf nodes have values 0 or 1.
     * - Internal nodes have values 2 (OR) or 3 (AND).
     * 
     * The function recursively evaluates the tree:
     * - If the node's value is 0 or 1, return it as a boolean.
     * - If the node's value is 2, evaluate the left and right subtrees and return their logical OR.
     * - If the node's value is 3, evaluate the left and right subtrees and return their logical AND.
     * 
     * @param n A pointer to the root node of the binary tree.
     * @return The boolean result of evaluating the tree.
     */
    bool evaluateTree(TreeNode* n) {
        switch (n->val) {
            case 0:
            case 1:
                return n->val; // Return the boolean value of the leaf node (0 or 1)
            case 2:
                return evaluateTree(n->left) || evaluateTree(n->right); // Logical OR for internal node with value 2
            default:
                return evaluateTree(n->left) && evaluateTree(n->right); // Logical AND for internal node with value 3
        }
    }
};

/* 
Explanation

In this C++ code:

    The TreeNode struct defines the structure of a binary tree node, which includes an integer value val and pointers to the left and right children.
    The Solution class contains the evaluateTree method, which evaluates the binary tree according to the following rules:
        Leaf nodes have values 0 or 1, representing boolean values false and true, respectively.
        Internal nodes have values 2 (representing the logical OR operation) or 3 (representing the logical AND operation).
    The method uses a switch statement to determine the type of node and recursively evaluates the left and right subtrees based on the node's value.

Complexity Analysis

    Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once.
    Space Complexity: O(h), where h is the height of the binary tree. This is due to the recursion stack.
 */