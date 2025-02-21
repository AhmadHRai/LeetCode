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
 class FindElements {
    public:
        // Constructor to initialize the FindElements object with a binary tree
        FindElements(TreeNode* root) {
            // Perform DFS to populate the set of values
            dfs(root, 0);
        }
    
        // Function to check if a target value exists in the tree
        bool find(int target) {
            // Return true if the target is in the set of values
            return seen.count(target) > 0;
        }
    
    private:
        // Set to store unique values from the binary tree
        unordered_set<int> seen;
    
        // Recursive DFS function to populate the set of values
        void dfs(TreeNode* currentNode, int currentValue) {
            // Base case: If the current node is null, return
            if (!currentNode)
                return;
    
            // Insert the current value into the set
            seen.insert(currentValue);
    
            // Recursively traverse the left and right subtrees
            dfs(currentNode->left, currentValue * 2 + 1);
            dfs(currentNode->right, currentValue * 2 + 2);
        }
    }
    /*
    Approach Summary:
    This solution uses a depth-first search (DFS) to populate a set with values from a binary tree, where each node's value is calculated based on its position in the tree. It then uses this set to efficiently check if a target value exists in the tree.
    
    Complexity Analysis:
    - Time Complexity:
      - Constructor: O(N), where N is the number of nodes in the tree, because each node is visited once.
      - `find`: O(1), because it simply checks if a value is in the set.
    - Space Complexity: O(N), for storing the set of values.
    */
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */