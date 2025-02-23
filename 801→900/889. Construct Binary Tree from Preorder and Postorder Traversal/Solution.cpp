/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

 class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int preIndex = 0;
            int postIndex = 0;
    
            return constructTree(preIndex, postIndex, preorder, postorder);
        }
    
    private:
        // Recursive function to construct the binary tree
        TreeNode* constructTree(int& preIndex, int& postIndex,
                                vector<int>& preorder, vector<int>& postorder) {
            // Create the root node using the current preorder value
            TreeNode* root = new TreeNode(preorder[preIndex]);
            preIndex++; // Move to the next preorder value
    
            // Check if the left subtree exists
            if (preIndex < preorder.size() && preorder[preIndex] != postorder[postIndex]) {
                // Recursively construct the left subtree
                root->left = constructTree(preIndex, postIndex, preorder, postorder);
            }
    
            // Check if the right subtree exists
            if (preIndex < preorder.size() && preorder[preIndex] != postorder[postIndex]) {
                // Recursively construct the right subtree
                root->right = constructTree(preIndex, postIndex, preorder, postorder);
            }
    
            postIndex++; // Move to the next postorder value
    
            return root;
        }
    }
    /*
    Approach Summary:
        This solution attempts to construct a binary tree from preorder and postorder traversals using a recursive approach. However, the current implementation has 
        logical errors in the recursive calls for constructing the left and right subtrees.
    
        A correct approach should involve identifying the root node from the preorder traversal, then recursively constructing the left and right subtrees based on the 
        postorder traversal. This typically involves finding the index of the root node in the postorder traversal to determine the sizes of the left and right subtrees.
    
    Complexity Analysis:
        Time Complexity: O(N), where N is the number of nodes in the tree, because each node is processed once.
        Space Complexity: O(N), for storing the recursion stack.
    */
    