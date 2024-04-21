/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int pseudoPalindromicPaths (TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int count) {
        if (root == null) return 0;
        count ^= 1 << (root.val - 1);
        int res = dfs(root.left, count) + dfs(root.right, count);
        if (root.left == root.right && (count & (count - 1)) == 0) res++;
        return res;
    }
}

/* 
Approach: Use an integer

    Recursively iterate all paths from root to leaves,
    count the occurrence of each digits in an integer.

    Use this integer as a bit mask.
    Also c++, we can use bitmask directly.

    Whenever meet an element,
    toggle the corresponding bit using ^ operation.

    At the leaf node,
    check if the count has only one bit that is 1.

    We use lowbit to help count this.
    Google it if you don't know.

Complexity:
    Time O(N)
    Space O(K + H)
 */