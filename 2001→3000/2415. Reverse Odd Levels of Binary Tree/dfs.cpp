// DFS with recursion (best runtime)
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverseDFS(root->left, root->right, 0);  // Start DFS with the left and right children of the root at level 0.
        return root;  // Return the modified tree root.
    }

private:
    void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if (leftChild == nullptr || rightChild == nullptr) {
            return;  // If either child is null, return.
        }

        // If the current level is odd, swap the values of the children.
        if (level % 2 == 0) {
            int temp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }

        // Recur for the next level with the appropriate left and right child pairs.
        traverseDFS(leftChild->left, rightChild->right, level + 1);
        traverseDFS(leftChild->right, rightChild->left, level + 1);
    }
};

/*
Approach:
    - This solution uses a recursive DFS approach to traverse the tree and process each level.
    - It starts by calling `traverseDFS` with the left and right children of the root node and level 0.
    - If the current level is odd, it swaps the values of the left and right children.
    - It then recurses down to the next level, passing the left and right children of the next level's nodes.
    - The recursion continues until all nodes are processed.

Complexity Analysis:
    - Time complexity: O(n)
      The recursive DFS visits each node once, and each operation (swap) takes constant time. Therefore, the time complexity is O(n), where n is the number of nodes in the tree.
    
    - Space complexity: O(h)
      The space complexity is determined by the depth of the recursion stack. In the worst case, where the tree is unbalanced, the recursion depth can be O(h), where h is the height of the tree. For a balanced binary tree, h = O(log n), making the space complexity O(log n).
*/
