/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 class FindElements {
    // Set to store unique values from the binary tree
    unordered_set<int> seen;

public:
    // Constructor to initialize the FindElements object with a binary tree
    FindElements(TreeNode* root) {
        // Perform BFS to populate the set of values
        bfs(root);
    }

    // Function to check if a target value exists in the tree
    bool find(int target) {
        // Return true if the target is in the set of values
        return seen.find(target) != seen.end();
    }

private:
    // BFS function to populate the set of values
    void bfs(TreeNode* root) {
        // Queue to manage nodes during BFS
        queue<TreeNode*> queue;

        // Initialize the root node's value and enqueue it
        root->val = 0;
        queue.push(root);

        // Perform BFS traversal
        while (!queue.empty()) {
            // Dequeue the next node
            TreeNode* current = queue.front();
            queue.pop();

            // Insert the current node's value into the set
            seen.insert(current->val);

            // Enqueue the left child if it exists
            if (current->left) {
                // Calculate the left child's value based on the parent's value
                current->left->val = current->val * 2 + 1;
                queue.push(current->left);
            }

            // Enqueue the right child if it exists
            if (current->right) {
                // Calculate the right child's value based on the parent's value
                current->right->val = current->val * 2 + 2;
                queue.push(current->right);
            }
        }
    }
}
/*
Approach Summary:
This solution uses a breadth-first search (BFS) to populate a set with values from a binary tree, where each node's value is calculated based on its position in the tree. It then uses this set to efficiently check if a target value exists in the tree.

Complexity Analysis:
- Time Complexity:
  - Constructor: O(N), where N is the number of nodes in the tree, because each node is visited once.
  - `find`: O(1), because it simply checks if a value is in the set.
- Space Complexity: O(N), for storing the set of values and the queue during BFS.
*/


/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */