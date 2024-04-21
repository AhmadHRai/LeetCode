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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            root=q.front();
            q.pop();
            if (root->right) {
                q.push(root->right);
            }
            if(root->left) q.push(root->left);
        }
        return root->val;
        
    }
};

/* 
Approach:
https://leetcode.com/problems/find-bottom-left-tree-value/solutions/4792343/easy-solution-beats-100-users-in-c-with-explanation

    To understand the approach for the provided code snippet, let's break it down step by step:

    Objective: The goal of this code is to find the value of the leftmost node in the bottom level of a binary tree.
    Algorithm:

    The code uses a breadth-first search (BFS) approach to traverse the binary tree level by level.

    It starts by initializing a queue q with the root node.
    Then, it enters a loop where it dequeues a node, checks if it has a right child, and if so, adds it to the queue. Next, it checks for a left child and adds it to the queue.

    By doing this level-order traversal, the last node visited will be the leftmost node at the bottom level of the tree.
    Key Points:
    The code prioritizes visiting right child nodes before left child nodes in each level.

    The final value returned is from the last node visited, which will be the leftmost node at the deepest level of the tree.

    This approach ensures that by traversing the tree level by level from left to right, we can find and return the value of the leftmost node at the deepest level of the binary tree.

Complexity

    Time complexity:0(n) each node is traversed once

    Space complexity:0(n) because of queue

 */