# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # This function takes the root node of a binary tree and returns the maximum absolute difference between any ancestor and descendant node values
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        # Initialize a class variable to store the global maximum difference
        self.res = 0
        # Define a helper function that takes a node and the current maximum and minimum values in the ancestor path
        def helper(node, max_val, min_val):
            # If the node is None, update the global maximum difference with the difference between the current maximum and minimum values
            if not node:
                self.res = max(self.res, max_val - min_val)
                return
            # Recursively call the helper function on the left and right children of the node, updating the maximum and minimum values with the node value
            helper(node.left, max(max_val, node.val), min(min_val, node.val))
            helper(node.right, max(max_val, node.val), min(min_val, node.val))
        # Call the helper function with the root node and initial maximum and minimum values
        helper(root, 0, 100000)
        # Return the global maximum difference
        return self.res

""" 
Some key notes:

    - The code uses a recursive depth-first search (DFS) algorithm to traverse the tree and keep track of the maximum and minimum values in the ancestor path of each node.
    - The code updates the global maximum difference with the absolute difference between the current maximum and minimum values whenever it reaches a leaf node or a None node.
    - The code uses a class variable to store the global maximum difference, so that it can be accessed and modified by the helper function.

Complexity:

    The time complexity is O(n), where n is the number of nodes in the tree. This is because the code visits each node once, and performs constant-time operations in each visit.
    The space complexity is O(h), where h is the height of the tree. This is because the code uses a recursive DFS algorithm, which uses a call stack to store the function 
    calls, and the size of the call stack is bounded by the height of the tree.
 """