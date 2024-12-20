// BFS
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;  // Return null if the tree is empty.
        }

        queue<TreeNode*> q;  // Queue to store nodes for level-order traversal (BFS).
        q.push(root);  // Start BFS with the root node.
        int level = 0;  // Track the current level of traversal.

        while (!q.empty()) {
            int size = q.size();  // Get the number of nodes at the current level.
            vector<TreeNode*> currentLevelNodes;  // To store nodes at the current level.

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();  // Remove the node from the queue.
                currentLevelNodes.push_back(node);  // Add node to the current level list.

                if (node->left) q.push(node->left);  // Add left child to the queue.
                if (node->right) q.push(node->right);  // Add right child to the queue.
            }

            // Reverse node values if the current level is odd.
            if (level % 2 == 1) {
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right) {
                    int temp = currentLevelNodes[left]->val;
                    currentLevelNodes[left]->val = currentLevelNodes[right]->val;
                    currentLevelNodes[right]->val = temp;  // Swap the values of nodes at opposite ends.
                    left++;
                    right--;
                }
            }

            level++;  // Increment the level after processing the current one.
        }

        return root;  // Return the modified tree.
    }
};

/*
Approach:
    - This solution uses a level-order traversal (BFS) to visit nodes level by level.
    - It processes all nodes at each level, stores them in a list, and if the level is odd, it reverses the node values within that list.
    - After processing a level, the children of the nodes are added to the queue for the next level's processing.
    - The BFS continues until all levels of the tree are processed.

Complexity Analysis:
    - Time complexity: O(n)
      We visit each node once, and for each node, we perform constant-time operations (adding to the queue, swapping values), making the overall time complexity O(n), where n is the number of nodes in the tree.

    - Space complexity: O(n)
      The space complexity is determined by the queue used for level-order traversal. In the worst case (a complete binary tree), the queue will hold up to n/2 nodes at a given level, leading to a space complexity of O(n).
*/
