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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) // if depth is 1, then we have to simply add root
        {
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode; // now this act as new root
        }
        
        queue<TreeNode*> q; // defineing queue
        q.push(root); // push queue
        int count = 0; // variable to count level
        
        // start bfs
        while(!q.empty()) 
        {
            // since we have to add values on all of the nodes
            // present at that level, so take out the size
            int n = q.size(); 
            
            count++; // increase size
            while(n--)
            {
                TreeNode* curr = q.front(); // take out current node
                q.pop(); // pop it from queue
                
                // if we not reach till our required level
                // so we have to do nothing, simply push into queue
                if(count != depth - 1) 
                {
                    if(curr -> left) q.push(curr -> left);
                    if(curr -> right) q.push(curr -> right);
                }
                else // else we reach our required level
                {
                    // make a new node to add
                    TreeNode* newNode = new TreeNode(val);
                    // first put left of curr to newNode
                    newNode -> left = curr -> left;
                    // now curr of left becomes newNode
                    curr -> left = newNode;
                    
                    // make a new node to add
                    TreeNode* newNode2 = new TreeNode(val);
                    // first put right of curr to newNode
                    newNode2 -> right = curr -> right;
                     // now curr of right becomes newNode
                    curr -> right = newNode2;
                }
            }
        }

        return root; // finally return right
    }
};

/*
Approach:
    1) We will use BFS here.

    WHY BFS ?
    2) Since we have to change the links at some particular level so the 
    very first thing that clicks to my mind is to used BFS. I just find it more intiuative.

    3) We will take a variable named as count, which will tell us 
    on which level we are currently standing.

    4) Note that the root node is at depth 1. So we have to check with (depth - 1).
    5) If (depth == 1) then we have to make a new node and left to it add the root node.
        And now our new node act as new root node.
        
    6) When we reach at the particular level where we have to add nodes, i.e level at (depth - 1)
    we make new nodes and add left value to left of new node and right value to right of new node.

    7) Note that, we first make put links in the new nodes, because if we put links first in current node
    then we loose connection that to be add in the new node.

    8) And from here we will not push anything into our queue, becuase our task is fullfilled and
    now further we do not have any requirement left.

Complexity:
    Time complexity: O(n), where n is the number of nodes in the tree. This complexity is linear because the code visits each node in 
    the tree once during the BFS traversal. 
    
    Space complexity: also O(n) because, in the worst-case scenario, the queue could potentially hold all nodes in the tree at the 
    same time.
*/