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
        vector<int> res; // create an empty vector to store the maximum value of each level
        dfs(root, 1, res); // call dfs function to traverse the tree and update the res vector
        return res; // return the res vector
    }

private:
    void dfs(TreeNode* node, int depth, vector<int>& res) {
        if (!node) { // if node is null, return
            return;
        }
        dfs(node->left, depth + 1, res); // traverse left subtree
        dfs(node->right, depth + 1, res); // traverse right subtree
        if (depth > res.size()) { // if current depth is greater than size of res vector, resize it and set all values to INT_MIN
            res.resize(depth, INT_MIN);
        }
        res[depth - 1] = max(res[depth - 1], node->val); // update the maximum value of current level in res vector
    }
};

/*
- Intuition:
    The problem requires finding the largest value at each level of a binary tree. By performing a depth-first search (DFS), 
    we can traverse each node while keeping track of the level depth. During traversal, we update the maximum value for each level in a result vector.

- Algorithm:
    1. Initialize an empty result vector `res` to store the largest values at each level.
    2. Perform a DFS traversal:
       - If the current node is null, return.
       - Traverse the left and right subtrees recursively, increasing the depth by 1.
       - If the current depth exceeds the size of the result vector, resize the vector and initialize new levels to `INT_MIN`.
       - Update the maximum value for the current level by comparing the node's value with the existing value in the result vector.
    3. Return the result vector containing the largest values for each level.

- Complexity:
    Time Complexity: O(n)
        - Each node in the binary tree is visited exactly once during the DFS traversal.
    Space Complexity: O(h)
        - The recursive calls use space proportional to the height of the tree `h` (call stack).
*/