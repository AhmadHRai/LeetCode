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
    //res to store maximum distance from the first infected node
    int res = 0;
    pair<bool,int> dfs(TreeNode* root, int start){
        if(!root) return {false,0};
        //return type pair states whether we came across start or not and maximum distance in this call
        pair<bool,int>p1 = dfs(root->left,start);
        pair<bool,int>p2 = dfs(root->right,start);
        // if we find the node then the maximum distance for now will be the maximum of 2 dfs calls and we will send the current distance as 0 to its parent(if exists)
        if(root->val==start){
            int temp = max(p2.second,p1.second);
            res = max(res,temp);
            return {true,0};
        }
        //if we find the start node to any of the dfs calls then the answer will be maximum of its previous value or sum of distance of start from this node and other path
        if(p1.first){
            int sum = p1.second+p2.second+1;
            res = max(res,sum);
            return {true,p1.second+1};
        }else if(p2.first){
            int sum = p1.second+p2.second+1;
            res = max(res,sum);
            return {true,p2.second+1};
        }
        //If we are still here, it means we have not come across the start node in this dfs call and hence will retuen maximum of 2 dfs calls
        int sum = max(p1.second,p2.second);
        return {false,1+sum};
    }
    
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        return res;
    }
};

/*
Complexity:
    The time complexity is O(n), where n is the number of nodes in the binary tree. This is because we use a depth-first search (DFS) algorithm to traverse the tree once, and 
    perform constant-time operations in each visit.
    
    The space complexity is O(h), where h is the height of the binary tree. This is because we use a recursive DFS algorithm, which uses a call stack to store the function 
    calls, and the size of the call stack is bounded by the height of the tree.
*/