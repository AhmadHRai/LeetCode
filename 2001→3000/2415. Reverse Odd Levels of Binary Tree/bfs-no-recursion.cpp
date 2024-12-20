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

#include <queue>
#include <utility>

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0; // Start from level 0, as the first level is considered even.

        if (!root) return nullptr;  // Return null if the root is null.

        queue<pair<TreeNode*, TreeNode*>> q;  // Queue to store pairs of left and right children at each level.
        q.push({root->left, root->right});    // Initially push the left and right children of the root.

        while (!q.empty()) {
            int size = q.size();  // Get the number of elements at the current level.

            for (int i = 0; i < size; ++i) {
                auto [leftChild, rightChild] = q.front();  // Get the pair of left and right children from the queue.
                q.pop();  // Remove the pair from the queue.

                if (!leftChild || !rightChild) continue;  // If either child is null, skip.

                // If the current level is odd, swap the values of the left and right children.
                if (level % 2 == 0) {
                    int temp = leftChild->val;
                    leftChild->val = rightChild->val;
                    rightChild->val = temp;
                }

                // Add the next level of children (left-left, right-right and left-right, right-left) to the queue.
                q.push({leftChild->left, rightChild->right});
                q.push({leftChild->right, rightChild->left});
            }

            ++level;  // Increment the level after processing the current one.
        }

        return root;  // Return the modified tree.
    }
};

/*
Approach:
    - This solution performs a level-order traversal (BFS) of the tree using a queue.
    - It processes nodes level by level, and on odd levels, it swaps the values of the left and right children.
    - After processing each level, the next level's left and right child pairs are added to the queue for further processing.
    - The first level is treated as level 0, and swapping happens on odd levels (level 1, 3, 5, etc.).

Complexity Analysis:
    - Time complexity: O(n)
      We visit each node once during the BFS traversal. Each operation (push, pop, swap) takes constant time, resulting in a total time complexity of O(n), where n is the number of nodes in the tree.
    
    - Space complexity: O(n)
      The space complexity is dominated by the queue used in the level-order traversal. In the worst case (a complete binary tree), the queue holds up to n/2 nodes at a level, leading to a space complexity of O(n).
*/
