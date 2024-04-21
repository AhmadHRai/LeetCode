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

#include <algorithm> // Include for the reverse function

class Solution {
public:
    string smallestLeafString = ""; // Holds the lexicographically smallest string from leaf to root.

    // Entry point to find the smallest string from leaf to root.
    string smallestFromLeaf(TreeNode* root) {
        string path = "";         // Represents the current path as a string.
        dfs(root, path);          // Start the DFS traversal.
        return smallestLeafString; // Return the smallest string after traversing the whole tree.
    }

    // Depth First Search (DFS) to traverse the tree.
    void dfs(TreeNode* node, string& path) {
        if (!node) return; // Base case: if the current node is nullptr, end the recursion.

        // Append the current character represented by the node's value to the path.
        path += 'a' + node->val;

        if (!node->left && !node->right) { // Check if it's a leaf node.
            string pathReversed = path;    // Create a copy of the current path to reverse it.
            reverse(pathReversed.begin(), pathReversed.end()); // Reverse the string to get the path from leaf to root.
            // Set smallestLeafString to the pathReversed if it's smaller than the current smallestLeafString or if smallestLeafString is empty.
            if (smallestLeafString.empty() || pathReversed < smallestLeafString) {
                smallestLeafString = pathReversed;
            }
        }

        // Continue the DFS traversal for both children.
        dfs(node->left, path);
        dfs(node->right, path);

        // Backtrack: Remove the last character as we return to the previous node.
        path.pop_back();
    }
};

/* 
Approach: 
    This solution works by performing a DFS traversal of the tree. For each node, it appends the character corresponding to the node's value to the current path. 
    If the node is a leaf (i.e., it has no children), it reverses the path to get the string from the leaf to the root and compares it with the current smallest string. 
    If the new string is lexicographically smaller, it updates the smallest string. Finally, it backtracks by removing the last character from the path as it returns to 
    the previous node. This process ensures that the lexicographically smallest string from a leaf to the root is found.

Complexity:
    
    The time complexity of the solution is O(N * M), where N is the number of nodes in the tree, and M is the maximum depth of the tree. This complexity arises because 
    the Depth-First Search (DFS) algorithm visits each node exactly once, and for each node, it performs operations that take constant time, such as appending to and 
    popping from the path list, and making a comparison to update the smallest string when a leaf is encountered. 
    
    The space complexity is O(M), which is required for the 
    recursion stack and the path list in the worst case when the tree is skewed.

    The DFS traversal ensures that each node is visited once, and the operations performed during this visit (appending to the path, reversing the path for leaf nodes, 
    and comparing strings) are constant time operations. The space complexity is determined by the depth of the tree, as in the worst-case scenario, the recursion stack 
    and the path list can grow up to the depth of the tree. This is because the path list needs to store the characters from the root to the current node, and in the 
    worst case, this list can grow up to the depth of the tree when the tree is skewed.

    In summary, the solution efficiently finds the lexicographically smallest string from a leaf to the root of a binary tree using DFS, with a time complexity of O(N * 
    M) and a space complexity of O(M).
 */