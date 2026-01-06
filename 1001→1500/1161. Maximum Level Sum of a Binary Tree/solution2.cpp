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
    void helper(TreeNode* root, vector<int>& sum, int l) {
        if (!root)
            return;

        if (sum.size() <= l) {
            sum.push_back(root->val);
        } else {
            sum[l] += root->val;
        }

        helper(root->left, sum, l + 1);
        helper(root->right, sum, l + 1);
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> sum;

        helper(root, sum, 0);

        auto it = max_element(sum.begin(), sum.end());

        return 1 + distance(sum.begin(), it);
    }
};
