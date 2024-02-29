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
    // Function to check if the given binary tree is an Even-Odd Tree.
    bool isEvenOddTree(TreeNode* root) {
        // If the root is null, the tree is trivially an Even-Odd Tree.
        if(root==NULL){
            return true;
        }
        // Queue to perform BFS traversal.
        queue<TreeNode*>q;
        // Flag to keep track of the level of the tree.
        bool flag=true;
      
        // Enqueue the root to start BFS.
        q.push(root);
        // BFS loop.
        while(!q.empty()){
            // Get the number of nodes at the current level.
            int x = q.size() ;
            // Initialize the previous node value based on the level.
            int prev = flag ? INT_MIN : INT_MAX;
            // Loop through each node at the current level.
            for(int i=0; i< x; i++){
                // Dequeue the front node.
                TreeNode* frontNode = q.front();
                q.pop();  
                // Check the conditions for odd and even levels.
                if(flag){
                    // For odd levels, the node value must be odd and greater than the previous node's value.
                    if(frontNode->val %2==0 || frontNode->val <= prev){
                     return false;
                    }
                }
                else{
                    // For even levels, the node value must be even and less than the previous node's value.
                    if(frontNode->val %2!=0 || frontNode->val >= prev){
                        return false;
                    }
                }

                // Enqueue the left and right children if they exist.
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                // Update the previous node value for the next iteration.
                prev= frontNode->val;
            }
            // Toggle the flag for the next level.
            flag=!flag;
        }
        // If all conditions are met, return true.
        return true;
    }
};

/* 
Approach

    The code checks if a given binary tree is an Even-Odd Tree. It uses a Breadth-First Search (BFS) to traverse the tree level by level. A queue is used to keep track of nodes at each 
    level. A boolean flag is used to determine whether the current level should have odd or even values. For odd levels, the node values must be odd and strictly greater than the 
    previous node's value. For even levels, the node values must be even and strictly less than the previous node's value. If any of these conditions are not met, the function returns 
    false. If all nodes satisfy these conditions, the function returns true.

Complexity

    Time complexity: O(n), where n is the number of nodes in the tree. This is because each node is visited exactly once during the BFS traversal.
    Space complexity: O(n), due to the use of a queue to store nodes at each level during the BFS traversal. In the worst-case scenario, this could be up to all nodes in the tree, especially if the tree is very unbalanced

 */