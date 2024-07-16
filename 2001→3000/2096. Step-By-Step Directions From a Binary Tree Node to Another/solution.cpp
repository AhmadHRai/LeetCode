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
    static string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathFrom, pathTo;
        
        // Compute the paths from root to startValue and destValue
        dfs(root, startValue, pathFrom);
        dfs(root, destValue, pathTo);

        // Find the point where paths diverge
        int n = pathFrom.size(), m = pathTo.size();
        int sz = 0;
        int minz = min(n, m);
        
        // Find the common prefix length
        while (sz < minz && pathFrom[sz] == pathTo[sz]) 
            sz++;

        // Construct the path from startValue to destValue
        return string(n - sz, 'U') + string(pathTo.begin() + sz, pathTo.end());
    }

private:
    static bool dfs(TreeNode* root, int x, string& path) {
        if (root == NULL)
            return false;
        if (root->val == x)
            return true;

        // Explore left subtree
        path.push_back('L');
        if (dfs(root->left, x, path)) return true;
        path.pop_back();

        // Explore right subtree
        path.push_back('R');
        if (dfs(root->right, x, path)) return true;
        path.pop_back();

        return false;
    }
};

/* 
Approach

    The solution finds the directions from one node to another in a binary tree.
    - Perform Depth-First Search (DFS) twice to compute the paths from the root to the `startValue` and `destValue`.
    - Compare the two paths to find the longest common prefix, which indicates the shared part of the paths.
    - Construct the result path by appending 'U' for each step up from the `startValue` to the point of divergence and then appending the path from that point to the `destValue`.

Complexity

    Time complexity: O(N), where N is the number of nodes in the tree. Each node is visited at most twice (once for each DFS call).
    
    Space complexity: O(N), due to the space required for storing paths and recursion stack.
 */
