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
    vector<TreeNode*> result;  // Vector to store the roots of the resulting trees
    set<int> to_delete_set;    // Set to quickly check if a node needs to be deleted

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Populate the set of nodes to delete
        for (int i : to_delete)
            to_delete_set.insert(i);
        
        // Start the recursive helper function
        helper(root, result, to_delete_set, true);
        return result;
    }

private:
    TreeNode* helper(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool is_root) {
        // Base case: if node is NULL, return NULL
        if (node == NULL) return NULL;
        
        // Check if the current node should be deleted
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        
        // If the current node is a root and should not be deleted, add it to the result
        if (is_root && !deleted) result.push_back(node);
        
        // Recursively process the left and right subtrees
        node->left = helper(node->left, result, to_delete_set, deleted);
        node->right = helper(node->right, result, to_delete_set, deleted);
        
        // Return NULL if the current node is deleted, otherwise return the node itself
        return deleted ? NULL : node;
    }
};

/* 
Approach

    The solution performs a post-order traversal of the binary tree to handle node deletions.
    - Use a set to keep track of nodes that need to be deleted.
    - For each node, if it is a root (determined by the `is_root` flag) and not in the delete set, add it to the result list.
    - Recursively process left and right children, passing along whether the current node was deleted to adjust its children's `is_root` flag.
    - After processing the subtrees, return NULL if the current node was deleted; otherwise, return the node itself.

Complexity

    Time complexity: O(N), where N is the number of nodes in the tree. Each node is visited once during the traversal.
    
    Space complexity: O(N), due to the space required for storing the resulting trees and recursion stack, as well as the set for delete operations.
 */
