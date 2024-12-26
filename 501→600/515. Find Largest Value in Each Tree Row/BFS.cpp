// largest_values_in_tree_bfs.cpp
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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{}; // If the tree is empty, return an empty vector
        }

        vector<int> ans; // Vector to store the largest value at each level
        queue<TreeNode*> queue; // Queue for BFS traversal
        queue.push(root); // Start BFS with the root node

        while (!queue.empty()) {
            int currentLength = queue.size(); // Number of nodes at the current level
            int currentMax = INT_MIN; // Initialize the maximum value for this level

            for (int i = 0; i < currentLength; i++) {
                TreeNode* node = queue.front(); // Get the front node in the queue
                queue.pop(); // Remove the node from the queue
                currentMax = max(currentMax, node->val); // Update the maximum value

                if (node->left) { // Add the left child to the queue if it exists
                    queue.push(node->left);
                }

                if (node->right) { // Add the right child to the queue if it exists
                    queue.push(node->right);
                }
            }
            ans.push_back(currentMax); // Add the largest value of the current level to the result
        }

        return ans; // Return the result vector
    }
};

/*
- Intuition:
    This solution uses a **Breadth-First Search (BFS)** approach to traverse the binary tree level by level.
    At each level, it calculates the largest value among all nodes and stores it in the result vector.

- Algorithm:
    1. If the root is null, return an empty vector as there are no values to process.
    2. Use a queue to perform BFS traversal:
        - Push the root node into the queue to start the traversal.
        - While the queue is not empty:
            a. Determine the number of nodes at the current level (`currentLength`).
            b. Initialize `currentMax` to `INT_MIN` to track the largest value for the level.
            c. Iterate through all nodes at the current level:
                - Dequeue a node, update `currentMax` with its value.
                - If the node has left and right children, enqueue them.
            d. Append `currentMax` to the result vector after processing all nodes at the level.
    3. Return the result vector containing the largest values at each level.

- Complexity:
    Time Complexity: O(n)
        - Each node in the tree is visited exactly once during the BFS traversal.
    Space Complexity: O(w)
        - The space required for the queue is proportional to the maximum width of the tree (`w`), which is the largest number of nodes at any level.
*/
