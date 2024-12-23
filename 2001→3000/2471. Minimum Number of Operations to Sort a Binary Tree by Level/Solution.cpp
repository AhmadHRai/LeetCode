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
    int minimumOperations(TreeNode* root) {
        TreeNode* nodeQueue[100000];  // Queue to hold nodes at each level
        int frontIndex = 0, backIndex = 0;
        nodeQueue[backIndex++] = root;  // Start by adding the root node to the queue
        int swapCount = 0;  // Count of the number of swaps needed

        // Perform level-order traversal using a queue (breadth-first search)
        while (backIndex - frontIndex > 0) {
            const int currentLevelSize = backIndex - frontIndex;  // Get the size of the current level
            int* levelIndices = (int*)alloca(currentLevelSize * sizeof(int));  // Array to store the indices of the nodes at the current level
            iota(levelIndices, levelIndices + currentLevelSize, 0);  // Initialize indices from 0 to currentLevelSize-1
            int* levelValues = (int*)alloca(currentLevelSize * sizeof(int));  // Array to store the values of the nodes at the current level

            // Collect node values at the current level and add child nodes to the queue
            for (int i = 0; i < currentLevelSize; i++) {
                auto currentNode = nodeQueue[frontIndex++];
                levelValues[i] = currentNode->val;

                // If the current node has children, add them to the queue for the next level
                if (currentNode->left) nodeQueue[backIndex++] = currentNode->left;
                if (currentNode->right) nodeQueue[backIndex++] = currentNode->right;
            }

            // Sort indices based on the values at the current level
            sort(levelIndices, levelIndices + currentLevelSize, [&](int i, int j) {
                return levelValues[i] < levelValues[j];  // Sort indices in increasing order of the node values
            });

            // Count the minimum swaps needed to sort the level values
            for (int i = 0; i < currentLevelSize;) {
                int j = levelIndices[i];  // Get the index of the node that should be at the current position
                if (j != i) {
                    swapCount++;  // Swap is required
                    swap(levelIndices[i], levelIndices[j]);  // Swap the indices
                } else {
                    i++;  // No swap needed, move to next element
                }
            }
        }

        return swapCount;  // Return the total count of swaps needed to sort all levels
    }
};

// Code to initialize fast input/output for competitive programming environments
auto initializeIO = []() {
    ios::sync_with_stdio(false);  // Disable synchronization with C I/O
    cin.tie(nullptr);  // Untie cin from cout to improve performance
    cout.tie(nullptr);  // Untie cout from cin
    return 'c';
}();

/**
 * Approach Summary:
 * 1. Perform level-order traversal (breadth-first search) of the tree using a queue.
 * 2. For each level, collect the values of all nodes at that level.
 * 3. Sort the node values at the current level and count how many swaps are needed to sort them.
 * 4. The number of swaps is determined by comparing the original node positions with their sorted positions.
 * 5. The total number of swaps required for the entire tree is accumulated and returned as the result.
 * 
 * The approach ensures that we visit each node only once and that we sort the values at each level in a manner
 * that is efficient. The number of swaps required at each level is determined by the difference between the
 * original positions of the nodes and their sorted order.
 * 
 * Time Complexity:
 * - The time complexity is O(n log n), where n is the total number of nodes in the tree.
 *   - O(n) for level-order traversal.
 *   - O(n log n) for sorting the nodes at each level.
 * 
 * Space Complexity:
 * - The space complexity is O(n), where n is the total number of nodes in the tree. This is due to the queue
 *   used for level-order traversal and the temporary arrays used to store node values and indices at each level.
 */