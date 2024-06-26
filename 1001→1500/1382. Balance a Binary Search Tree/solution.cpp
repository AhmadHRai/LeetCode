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
    vector<TreeNode*> sortedArr;  // Vector to store nodes in sorted order

    // Function to balance the BST
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);  // Perform inorder traversal to populate sortedArr
        return sortedArrayToBST(0, sortedArr.size() - 1);  // Convert sortedArr to balanced BST
    }

    // Helper function to perform inorder traversal and populate sortedArr
    void inorderTraverse(TreeNode* root) {
        if (root == nullptr) return;  // Base case: if root is null, return
        inorderTraverse(root->left);  // Traverse left subtree
        sortedArr.push_back(root);    // Add current node to sortedArr
        inorderTraverse(root->right); // Traverse right subtree
    }

    // Helper function to convert sorted array to balanced BST
    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) return nullptr;  // Base case: if start index exceeds end index, return null

        int mid = (start + end) / 2;  // Calculate middle index
        TreeNode* root = sortedArr[mid];  // Create new node with middle element as root
        root->left = sortedArrayToBST(start, mid - 1);  // Recursively build left subtree
        root->right = sortedArrayToBST(mid + 1, end);   // Recursively build right subtree
        return root;  // Return the constructed BST
    }
};

/*
Approach:
- Define a TreeNode structure to represent nodes in a binary tree.
- Implement a Solution class with:
  - sortedArr vector to store nodes in sorted order during traversal.
  - balanceBST function to balance the provided binary search tree (BST).
  - inorderTraverse function to perform inorder traversal of the BST and populate sortedArr.
  - sortedArrayToBST function to recursively convert sortedArr into a balanced BST.
- Inorder Traversal:
  - Traverse the BST recursively in an inorder manner (left subtree, current node, right subtree).
  - Store each visited node in sortedArr.
- Convert Sorted Array to Balanced BST:
  - Determine the middle index of the current segment of sortedArr.
  - Use the middle element as the root of the subtree.
  - Recursively build the left subtree with elements before the middle index.
  - Recursively build the right subtree with elements after the middle index.
  - Return the root of the constructed subtree.
- Return the root of the balanced BST generated from the input BST.

Complexity Analysis:
- Time Complexity:
  - Inorder Traversal: O(n), where n is the number of nodes in the input BST.
    - Each node is visited exactly once.
  - Sorted Array to BST Conversion: O(n), where n is the number of nodes in the input BST.
    - Each element in sortedArr is processed exactly once to construct the BST recursively.
  - Overall Time Complexity: O(n), dominated by the recursive processes of inorder traversal and BST construction.
- Space Complexity:
  - sortedArr: O(n), where n is the number of nodes in the input BST.
    - Additional space used to store nodes during traversal.
  - Recursive Stack: O(log n) on average for a balanced BST.
    - Space used by the function call stack during recursive operations.
  - Overall Space Complexity: O(n) in the worst case, considering both sortedArr and recursive stack space.
*/
