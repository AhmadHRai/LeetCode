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
    // Function to determine if two binary trees are flip equivalent
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Check if both trees are null (flip equivalent)
        if ( !root1 && !root2 ) return true;
        // Check if one tree is null and the other is not (not flip equivalent)
        if ( !root1 && root2 || root1 && !root2 || root1->val != root2->val ) return false;
        
        // Recursively check for flip equivalence in two cases:
        // 1. No flip: left subtree of tree1 with left subtree of tree2 and right subtree of tree1 with right subtree of tree2
        // 2. Flip: right subtree of tree1 with left subtree of tree2 and left subtree of tree1 with right subtree of tree2
        return flipEquiv( root1->left, root2->left ) && flipEquiv( root1->right, root2->right )
            || flipEquiv( root1->right, root2->left ) && flipEquiv( root1->left, root2->right );
    }
};

/*
Approach:

    This solution uses a recursive approach to determine if two binary trees are flip equivalent.
    It first checks for base cases where both trees are null or one is null.
    If the root values of both trees are not equal, they cannot be flip equivalent.
    The function then recursively checks the subtrees in two configurations:
    - Without flipping the subtrees (both left and right).
    - With flipping the subtrees (left of one tree with the right of another and vice versa).

Complexity:

    Time Complexity: O(n), where n is the number of nodes in the trees, since each node is visited once.
    Space Complexity: O(h), where h is the height of the trees, due to the recursion stack.

Comments:
    Two null trees are flip equivalent
    A non-null and null tree are NOT flip equivalent
    Two non-null trees with different root values are NOT flip equivalent
    Two non-null trees are flip equivalent if
            The left subtree of tree1 is flip equivalent with the left subtree of tree2 and the right subtree of tree1 is   
            flipequivalent with the right subtree of tree2 (no flip case)
            OR
            The right subtree of tree1 is flip equivalent with the left subtree of tree2 and the left subtree of tree1 is
            flipequivalent with the right subtree of tree2 (flip case)


This approach effectively determines if two binary trees can be made equivalent through flipping.
*/
