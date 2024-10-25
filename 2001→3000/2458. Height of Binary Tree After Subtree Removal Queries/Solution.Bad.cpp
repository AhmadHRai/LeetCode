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
    vector<int> depth, levelArr, max1, max2; // Vectors to store depths, levels, and max depths

    // Recursive function to compute the height of the tree and update max depths
    int height(TreeNode* root, int level) {
        if (!root) return 0; // Base case: if the node is null, return 0

        // Store the level of the current node
        levelArr[root->val] = level;
        
        // Compute the depth of the current node
        depth[root->val] = 1 + max(height(root->left, level + 1), height(root->right, level + 1));

        // Update max1 and max2 for the current level based on the computed depth
        if (max1[level] < depth[root->val]) {
            max2[level] = max1[level]; // Update second max depth
            max1[level] = depth[root->val]; // Update max depth
        } else if (max2[level] < depth[root->val]) {
            max2[level] = depth[root->val]; // Update second max depth
        }

        return depth[root->val]; // Return the depth of the current node
    }

    // Function to process queries and compute the results
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Resize vectors to hold values for nodes up to 100001
        depth.resize(100001, 0);
        levelArr.resize(100001, 0);
        max1.resize(100001, 0);
        max2.resize(100001, 0);

        // Compute depths and max depths for each level of the tree
        height(root, 0);

        // Process each query to compute the result
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i]; // Get the current query node
            int level = levelArr[q]; // Find its level
            
            // Compute the result based on max depths
            queries[i] = (max1[level] == depth[q] ? max2[level] : max1[level]) + level - 1;
        }

        return queries; // Return the results of the queries
    }
};

/*
Approach:

    This solution computes the maximum depth of nodes in a binary tree and answers queries regarding the maximum depth
    when a specified node is removed. It uses a depth-first search (DFS) approach to traverse the tree, calculating
    the depth of each node and tracking the maximum and second maximum depths for each level of the tree.
    Each query is then processed using this information to find the appropriate maximum depth after the removal of the queried node.

Complexity:

    Time Complexity: O(n + m), where n is the number of nodes in the tree (for DFS traversal) and m is the number of queries.
    Space Complexity: O(n) for storing depths and levels, which can be up to the number of nodes in the tree.

This approach efficiently computes the required values while managing the data structures needed to handle multiple queries.
*/
