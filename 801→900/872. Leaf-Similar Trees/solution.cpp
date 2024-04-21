class Solution {
public:
    // This function takes two binary trees and returns true if they are leaf-similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Create two stacks to store the nodes of the trees
        stack<TreeNode*> s1 , s2;
        // Push the root nodes of the trees to the stacks
        s1.push(root1); s2.push(root2);
        // Loop until both stacks are empty
        while (!s1.empty() && !s2.empty())
            // Pop the top nodes from the stacks and compare their leaf values using the dfs helper function
            // If the leaf values are different, return false
            if (dfs(s1) != dfs(s2)) return false;
        // Return true if both stacks are empty, meaning the trees have the same number of leaves
        return s1.empty() && s2.empty();
    }

    // This helper function takes a stack of tree nodes and returns the next leaf value
    int dfs(stack<TreeNode*>& s) {
        // Loop until a leaf node is found
        while (true) {
            // Pop the top node from the stack
            TreeNode* node = s.top(); s.pop();
            // If the node has a right child, push it to the stack
            if (node->right) s.push(node->right);
            // If the node has a left child, push it to the stack
            if (node->left) s.push(node->left);
            // If the node is a leaf node, return its value
            if (!node->left && !node->right) return node->val;
        }
    }
};

/* 
Complexity:
    
    The time complexity is O(n), where n is the total number of nodes in both trees. This is because the code visits each node at most once, and performs constant-time 
    operations in each visit.
    
    The space complexity is O(h), where h is the maximum height of the trees. This is because the code uses two stacks to store the nodes, and the size of the stacks is bounded 
    by the height of the trees.
 */