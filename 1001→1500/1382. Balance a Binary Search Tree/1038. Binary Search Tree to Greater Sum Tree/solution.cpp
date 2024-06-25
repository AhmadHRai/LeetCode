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
    TreeNode* bstToGst(TreeNode* root) {
        int acc_sum = 0;  // Initialize a variable to accumulate the sum
        sum_node(root, acc_sum);  // Perform the recursive sum update starting from the root
        return root;  // Return the modified root of the BST
    }

private:
    // Helper function to recursively update node values with accumulated sum
    void sum_node(TreeNode* node, int& acc_sum) {
        if (node == nullptr) return;  // Base case: if node is null, return
        sum_node(node->right, acc_sum);  // Recursively traverse right subtree
        node->val += acc_sum;  // Update current node value with accumulated sum
        acc_sum = node->val;  // Update accumulated sum with current node value
        sum_node(node->left, acc_sum);  // Recursively traverse left subtree
    }
};

/*
Approach:
- Define a TreeNode structure to represent nodes in a binary tree.
- Implement a Solution class with:
  - bstToGst function to perform the required transformation on the BST.
  - sum_node private helper function to recursively update node values with accumulated sum.
- BST to GST Transformation:
  - Perform a reverse in-order traversal of the BST using the sum_node function.
  - Start from the rightmost node, recursively update node values by adding the accumulated sum.
  - Update the accumulated sum with the current node value after each update.
  - Continue the traversal to the left subtree after processing the current node.
- Return the root of the modified BST after completing the transformation.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of nodes in the BST.
  - Each node is visited exactly once in the reverse in-order traversal.
  - Updating node values and accumulating sums are constant-time operations.
- Space Complexity: O(h), where h is the height of the BST.
  - Space used by the function call stack during recursive traversal.
  - In the worst case, for a skewed BST, the space complexity is O(n).
  - On average, for a balanced BST, the space complexity is O(log n).
*/
