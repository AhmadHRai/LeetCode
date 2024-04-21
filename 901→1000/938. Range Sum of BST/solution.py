# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # This function takes the root node of a binary search tree and two integers L and R, and returns the sum of values of all nodes with a value in the inclusive range [L, R]
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        # Create a stack to store the nodes of the tree
        stk, sum = [root], 0
        # Loop until the stack is empty
        while stk:
            # Pop the top node from the stack
            node = stk.pop()
            # If the node is not None
            if node:
                # If the node value is greater than L, push its left child to the stack
                if node.val > L:
                    stk.append(node.left)    
                # If the node value is less than R, push its right child to the stack
                if node.val < R:
                    stk.append(node.right)
                # If the node value is in the range [L, R], add it to the sum
                if L <= node.val <= R:
                    sum += node.val    
        # Return the sum
        return sum

"""
Complexity:
    The time complexity is O(n), where n is the number of nodes in the tree. This is because the code visits each node at most once, and performs constant-time operations in 
    each visit.
    
    The space complexity is O(h), where h is the height of the tree. This is because the code uses a stack to store the nodes, and the size of the stack is bounded by the height 
    of the tree.
"""