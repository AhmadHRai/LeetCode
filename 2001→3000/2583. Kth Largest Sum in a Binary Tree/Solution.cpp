#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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
    // Function to find the k-th largest level sum in a binary tree
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Return -1 if the tree is empty
        if (!root) return -1;

        // Vector to store the sum of each level
        vector<long long> levelSums;
        // Queue for level order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level order traversal
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int levelSize = q.size();
            long long levelSum = 0; // Initialize the sum for this level

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); // Get the front node
                q.pop(); // Remove the node from the queue
                levelSum += node->val; // Add its value to the level sum

                // Add child nodes to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            // Store the sum of the current level
            levelSums.push_back(levelSum);
        }

        // Sort the level sums in descending order
        sort(levelSums.rbegin(), levelSums.rend());

        // Check if there are at least k levels
        if (k > levelSums.size()) {
            return -1; // Not enough levels
        }

        // Return the k-th largest level sum
        return levelSums[k - 1];
    }
};

/*
Approach:

    This solution uses a breadth-first search (BFS) approach to traverse the binary tree level by level.
    A queue is employed to facilitate the level order traversal, and the sum of values at each level is calculated and stored.
    After all levels have been processed, the level sums are sorted in descending order to retrieve the k-th largest sum.

Complexity:

    Time Complexity: O(n log n) due to the sorting of level sums, where n is the number of nodes in the tree.
    Space Complexity: O(n) to store the level sums and the queue used for BFS traversal.

This approach efficiently computes the k-th largest level sum while adhering to the problem constraints.
*/