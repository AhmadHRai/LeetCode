class Solution {
public:
    // Array to store the maximum height of the tree after removing each node
    int maxHeightAfterRemoval[100001]; // Max height after removal for each node
    int currentMaxHeight = 0; // Current maximum height during traversal

    // Main function to process tree queries
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root, 0); // First traversal from left to right
        currentMaxHeight = 0;  // Reset for the second traversal
        traverseRightToLeft(root, 0); // Second traversal from right to left

        // Process queries and build the result vector
        int queryCount = queries.size();
        vector<int> queryResults(queryCount);
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]]; // Get results for each query
        }

        return queryResults; // Return the results of the queries
    }

private:
    // Left to right traversal to calculate maximum heights
    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        if (node == nullptr) return; // Base case: if the node is null, return

        // Store the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] = currentMaxHeight;

        // Update the current maximum height
        currentMaxHeight = max(currentMaxHeight, currentHeight);

        // Traverse left subtree first, then right
        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    // Right to left traversal to calculate maximum heights
    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        if (node == nullptr) return; // Base case: if the node is null, return

        // Update the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] =
            max(maxHeightAfterRemoval[node->val], currentMaxHeight);

        // Update the current maximum height
        currentMaxHeight = max(currentHeight, currentMaxHeight);

        // Traverse right subtree first, then left
        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};

/*
Approach:

    The solution computes the maximum height of a binary tree after the removal of each node. 
    It performs two traversals: one from left to right and another from right to left. 
    During each traversal, the current maximum height is updated and stored for each node in the 
    `maxHeightAfterRemoval` array. This allows for efficient computation of the maximum height after 
    removing any specified node.

Complexity:

    Time Complexity: O(n), where n is the number of nodes in the tree, as each node is visited twice.
    Space Complexity: O(n) for the `maxHeightAfterRemoval` array that holds the maximum heights.

This approach efficiently computes the desired heights for each query using depth-first traversal strategies.
*/
