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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; // Value of the node
 *     TreeNode *left; // Pointer to the left child
 *     TreeNode *right; // Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor with value and children
 * };
 */
class Solution {
public:
    int answer =  0; // Initialize variable to store the diameter of the tree

    int dfs(TreeNode* root) {
        if (!root) return  0; // Base case: if the node is null, return  0

        int leftDepth = dfs(root->left); // Recursively find the depth of the left subtree
        int rightDepth = dfs(root->right); // Recursively find the depth of the right subtree

        root->left = root->right = NULL; // Nullify the left and right children of the current node

        answer = max(answer, leftDepth + rightDepth); // Update the answer with the maximum of the current answer and the sum of left and right depths

        return  1 + max(leftDepth, rightDepth); // Return the depth of the current node, which is  1 plus the maximum depth of the left or right subtree
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root); // Call the dfs function to calculate the diameter of the tree
        return answer; // Return the calculated diameter
    }
};

/* 
Time Complexity Analysis:
    The time complexity of this algorithm is O(n), where n is the number of nodes in the binary tree. This is because each node is visited exactly once during the depth-first search 
    (DFS) traversal.

Space Complexity Analysis:
    The space complexity is O(h), where h is the height of the binary tree. This is because the maximum amount of space is used by the call stack during the recursive DFS traversal, 
    which in the worst case is proportional to the height of the tree.
 */