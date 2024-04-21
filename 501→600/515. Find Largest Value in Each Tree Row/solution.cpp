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
The time complexity of the dfs function in the code is O(n), where n is the number of nodes in the binary tree. This is because the function visits each node in the tree 
exactly once, and the time required to visit each node is constant. The space complexity of the function is O(h), where h is the height of the tree. This is because the 
function uses a recursive approach to traverse the tree, and the maximum depth of the recursion is equal to the height of the tree. Therefore, the space required by the 
function on the call stack is proportional to the height of the tree
*/