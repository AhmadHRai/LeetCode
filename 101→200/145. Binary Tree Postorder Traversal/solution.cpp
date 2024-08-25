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
    // Function to perform postorder traversal of a binary tree
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes; // Vector to store the values of nodes in postorder
        postorder(root, nodes); // Call helper function to fill the vector
        return nodes; // Return the vector with node values in postorder
    }

private:
    // Helper function for postorder traversal
    void postorder(TreeNode* root, vector<int> &nodes) {
        if (!root) {
            return; // Base case: if the current node is null, return
        }
        postorder(root->left, nodes); // Recursively traverse the left subtree
        postorder(root->right, nodes); // Recursively traverse the right subtree
        nodes.push_back(root->val); // Visit the current node and add its value to the vector
    }
};

/*
Approach Summary:
- Perform a postorder traversal of a binary tree. In postorder traversal, the left subtree is visited first, then the right subtree, and finally the root node.
- Use a helper function `postorder` to recursively traverse the tree and collect node values in postorder.
- The `postorderTraversal` function initializes a vector to store node values, calls the helper function, and returns the vector.

Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is visited exactly once.

Space Complexity:
- O(n), where n is the number of nodes in the tree. The space is used to store the result vector and the recursion stack.
*/
