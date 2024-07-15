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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Define constants and initialize data structures
        const int N = 100001;
        bitset<N> seen; // Bitset to track seen nodes
        int root = -1;  // Variable to store the root node's value
        int parent[N] = {0}; // Array to store parent values
        TreeNode* node[N] = {NULL}; // Array to store pointers to TreeNode objects

        // Iterate through each description
        for (auto& d : descriptions) {
            int x = d[0], y = d[1], l = d[2];
            
            // Create a new TreeNode for x if it does not exist
            if (!seen[x]) {
                node[x] = new TreeNode(x);
                seen[x] = 1;
                if (parent[x] == 0) {
                    root = x; // x is initially considered as root
                }
            }
            
            // Create a new TreeNode for y if it does not exist
            if (!seen[y]) {
                node[y] = new TreeNode(y);
                seen[y] = 1;
            }
            
            // Set parent of y
            parent[y] = x;
            
            // Attach y as left or right child of x based on l
            if (l)
                node[x]->left = node[y];
            else
                node[x]->right = node[y];
        }
        
        // Find the actual root of the tree
        while (parent[root] != 0)
            root = parent[root];
        
        // Return the root node of the constructed tree
        return node[root];
    }
};

/* 
Approach

    The solution constructs a binary tree from a list of descriptions.
    - Use a bitset to keep track of which nodes have been created to avoid duplicates.
    - Use arrays to map node values to their TreeNode objects and track their parent relationships.
    - For each description, create TreeNode objects as needed, set parent-child relationships, and determine the root of the tree.
    - Finally, traverse the parent array to find the actual root of the tree and return it.

Complexity

    Time complexity: O(N), where N is the number of descriptions. Each description is processed once to create nodes and set relationships.
    
    Space complexity: O(N), due to the space required for storing node pointers and parent relationships in arrays.
 */
