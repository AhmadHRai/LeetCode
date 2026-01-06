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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int level = 0;
        int maxSum = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            level++;
            int currentSum = 0;

            for (int sz = q.size(); sz > 0; sz--) {
                TreeNode* node = q.front();
                q.pop();
                currentSum += node->val;

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            if (maxSum < currentSum) {
                maxSum = currentSum;
                ans = level;
            }
        }

        return ans;
    }
};
