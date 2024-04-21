# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        # If both nodes are None, they are identical
        if p is None and q is None:
            return True
        # If only one of the nodes is None, they are not identical
        if p is None or q is None:
            return False
        # Check if values are equal and recursively check left and right subtrees
        if p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        # Values are not equal, they are not identical
        return False

"""
Approach

    Check the base case: if both trees are null, return true.
    Check if only one tree is null or the values of the current nodes are different, return false.
    Recursively check if the left subtrees of both trees are identical.
    Recursively check if the right subtrees of both trees are identical.
    Return the logical AND of the results from steps 3 and 4.

Complexity

    Time complexity:
    The time complexity of the solution is O(min(N,M)), where N and M are the number of nodes in the two trees, respectively. This is because we need to visit each node once in order to compare their values. In the worst case, where both trees have the same number of nodes, the time complexity would be O(N).

    Space complexity:
    The space complexity of the solution isO(min(H1,H2)), where H1 and H2 are the heights of the two trees, respectively. This is because the space used by the recursive stack is determined by the height of the smaller tree. In the worst case, where one tree is significantly larger than the other, the space complexity would be closer to O(N) or O(M), depending on which tree is larger.

"""