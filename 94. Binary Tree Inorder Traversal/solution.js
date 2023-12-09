/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

/**
 * @param {TreeNode} root
 * @return {number[]}
 */

var inorderTraversal = function (root) {
  let ans = [];
  let tree = function (root, ans) {
    if (!root) {
      return;
    }

    if (root.left) {
      tree(root.left, ans);
    }

    ans.push(root.val);

    if (root.right) {
      tree(root.right, ans);
    }
  };

  tree(root, ans);
  return ans;
};
