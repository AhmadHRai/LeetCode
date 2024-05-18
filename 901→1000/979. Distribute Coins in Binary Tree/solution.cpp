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
    int res = 0; // Variable to keep track of the number of moves required

    /**
     * This function calculates the number of moves required to distribute coins in a binary tree such that
     * each node has exactly one coin.
     * 
     * The function uses a depth-first search (DFS) approach to traverse the tree and calculate the balance
     * of coins at each node. The balance is the number of excess coins a node has (positive or negative).
     * 
     * @param root A pointer to the root node of the binary tree.
     * @return The total number of moves required to distribute the coins.
     */
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }

private:
    /**
     * This helper function performs a depth-first search (DFS) on the tree to calculate the coin balance
     * for each node and update the total number of moves required.
     * 
     * @param root A pointer to the current node in the binary tree.
     * @return The coin balance of the current node.
     */
    int dfs(TreeNode* root) {
        if (!root) return 0; // Base case: if the node is null, return a balance of 0
        int left = dfs(root->left); // Recursively calculate the coin balance of the left subtree
        int right = dfs(root->right); // Recursively calculate the coin balance of the right subtree
        res += abs(left) + abs(right); // Update the total moves with the absolute balances of the left and right subtrees
        // Return the current node's balance: its value plus the balances of its subtrees minus 1 (since it needs 1 coin for itself)
        return root->val + left + right - 1;
    }
};

/* 
Explanation

In this C++ code:

    The TreeNode struct defines the structure of a binary tree node, which includes an integer value val and pointers to the left and right children.
    The Solution class contains the distributeCoins method, which calculates the number of moves required to distribute coins in a binary tree so that each node has exactly one coin.
    The res variable keeps track of the total number of moves required.
    The distributeCoins method calls the private helper method dfs to perform a depth-first search on the tree and calculate the coin balance for each node.
    The dfs method calculates the coin balance for the current node by recursively processing the left and right subtrees, updating the total moves with the absolute balances of the subtrees, and returning the current node's balance.

Complexity Analysis

    Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once.
    Space Complexity: O(h), where h is the height of the binary tree. This is due to the recursion stack.
 */