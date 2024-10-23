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
    // Main function to replace values in the binary tree
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Set the value of the root node to 0
        root->val = 0;
        // Start depth-first search (DFS) from the root
        dfs(vector<TreeNode*>{root});
        // Return the modified tree
        return root;
    }
private:
    // DFS function to traverse the tree and update node values
    void dfs(vector<TreeNode*> arr) {
        // Base case: if the array is empty, return
        if (arr.empty()) return;

        int sum = 0; // Variable to store the sum of child values
        // Calculate the sum of the values of all left and right children
        for (auto node : arr) {
            if (!node) continue; // Skip null nodes
            if (node->left) sum += node->left->val; // Add left child value to sum
            if (node->right) sum += node->right->val; // Add right child value to sum
        }

        vector<TreeNode*> childArr; // Array to hold child nodes for the next DFS call
        // Update the values of the children based on the calculated sum
        for (auto node : arr) {
            int curSum = 0; // Variable to store the sum of current node's children
            if (node->left) curSum += node->left->val; // Sum left child value
            if (node->right) curSum += node->right->val; // Sum right child value

            // Update left child value
            if (node->left) {
                node->left->val = sum - curSum; // Set new value for left child
                childArr.push_back(node->left); // Add left child to the next level array
            }
            // Update right child value
            if (node->right) {
                node->right->val = sum - curSum; // Set new value for right child
                childArr.push_back(node->right); // Add right child to the next level array
            }
        }

        // Recursively call DFS on the children
        dfs(childArr);
    }
};

/*
Approach:

    The solution uses a depth-first search (DFS) approach to traverse the binary tree.
    Initially, the root node is set to 0, and the DFS function is called with the root node.
    For each node, the sum of the values of its children is calculated, and then the values of the children are updated to reflect the difference between the total sum of all children and their current values.
    This process continues recursively until all nodes have been processed.

Complexity:

    Time Complexity: O(n), where n is the number of nodes in the tree, as each node is visited exactly once.
    Space Complexity: O(h), where h is the height of the tree, due to the recursion stack.

This approach efficiently updates the values in the binary tree according to the specified rules.
*/
