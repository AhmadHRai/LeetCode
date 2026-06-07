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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        static TreeNode nodes[100001];
        static bool hasParent[100001] = {};
        static int generation[100001] = {};
        static int currentGeneration = 0;

        ++currentGeneration;

        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal  = desc[1];
            bool isLeft   = desc[2];

            if (generation[parentVal] != currentGeneration) {
                nodes[parentVal].val = parentVal;
                nodes[parentVal].left = nullptr;
                nodes[parentVal].right = nullptr;
                generation[parentVal] = currentGeneration;
            }

            if (generation[childVal] != currentGeneration) {
                nodes[childVal].val = childVal;
                nodes[childVal].left = nullptr;
                nodes[childVal].right = nullptr;
                generation[childVal] = currentGeneration;
            }

            if (isLeft) {
                nodes[parentVal].left = &nodes[childVal];
            } else {
                nodes[parentVal].right = &nodes[childVal];
            }

            hasParent[childVal] = true;
        }

        int rootValue = -1;

        for (const auto& desc : descriptions) {
            int parentVal = desc[0];

            if (!hasParent[parentVal]) {
                rootValue = parentVal;
                break;
            }
        }

        // Cleanup for next test case
        for (const auto& desc : descriptions) {
            hasParent[desc[0]] = false;
            hasParent[desc[1]] = false;
        }

        return &nodes[rootValue];
    }
};
