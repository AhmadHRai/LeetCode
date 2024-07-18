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
    // Recursive function to find the distances and count valid pairs
    vector<int> recur(TreeNode* root, int distance, int &cnt) {
        if (!root) return {0}; // If the node is NULL, return an empty distance list

        // If it's a leaf node, return a list with a single entry of 1
        if (!root->left && !root->right) return {1};

        // Recursively get distances from left and right subtrees
        vector<int> left = recur(root->left, distance, cnt);
        vector<int> right = recur(root->right, distance, cnt);

        // Check for pairs of nodes across the left and right subtrees
        for (int x : left) {
            for (int y : right) {
                if (x > 0 && y > 0 && x + y <= distance) {
                    cnt++; // Increment count if the distance between the pair is within the limit
                }
            }
        }

        // Prepare a list of distances from the current node
        vector<int> ans;
        for (int x : left) {
            if (x > 0 && x < distance) {
                ans.push_back(x + 1); // Increment distance for nodes from left subtree
            }
        }
        for (int x : right) {
            if (x > 0 && x < distance) {
                ans.push_back(x + 1); // Increment distance for nodes from right subtree
            }
        }

        return ans; // Return the updated list of distances
    }

    int countPairs(TreeNode* root, int distance) {
        int cnt = 0; // Initialize the count of valid pairs
        recur(root, distance, cnt); // Start the recursive counting
        return cnt; // Return the total count of valid pairs
    }
};

/* 
Approach

    The solution counts the number of good leaf node pairs in a binary tree where the distance between the leaf nodes is less than or equal to the given maximum distance.
    - Use a recursive function to traverse the tree and compute distances between leaf nodes.
    - For each node, determine distances of leaf nodes in its subtrees and count valid pairs where the sum of distances does not exceed the given distance.
    - Collect and update distances of nodes as the recursion unwinds.

Complexity

    Time complexity: O(N^2), where N is the number of nodes in the tree. Each node might be compared with every other node to determine valid pairs.
    
    Space complexity: O(H), where H is the height of the tree, due to the space required for recursion stack and storing distances.
 */
