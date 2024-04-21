# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers1(self, root): # DFS recursively 
        """
        This method uses Depth-First Search (DFS) to traverse the binary tree. It starts from the root and explores as far as possible along each branch before backtracking.
        The path from the root to a leaf node is treated as a number, and the sum of all such numbers is calculated.
        """
        self.res = 0
        self.dfs(root, 0)
        return self.res
    
    def dfs(self, root, path):
        if root:
            # If the current node is a leaf node, add the path value to the result
            if not root.left and not root.right:
                path = path*10 + root.val
                self.res += path
            # Recursively call DFS on the left and right children, appending the current node's value to the path
            self.dfs(root.left, path*10+root.val)
            self.dfs(root.right, path*10+root.val)
            
    def sumNumbers2(self, root): # BFS with queue
        """
        This method uses Breadth-First Search (BFS) with a queue to traverse the binary tree level by level.
        It modifies the value of each node to include the path value from the root to that node, and then sums up these values.
        """
        deque, res = collections.deque(), 0
        if root:
            deque.append(root)
        while deque:
            node = deque.popleft()
            # If the current node is a leaf node, add its value to the result
            if not node.left and not node.right:
                res += node.val
            # Enqueue the left and right children, updating their values to include the path from the root
            if node.left:
                node.left.val += node.val*10
                deque.append(node.left)
            if node.right:
                node.right.val += node.val*10
                deque.append(node.right)
        return res
    
    def sumNumbers(self, root): # DFS with stack
        """
        This method uses Depth-First Search (DFS) with a stack to traverse the binary tree.
        Similar to the recursive DFS, it treats the path from the root to a leaf node as a number and sums these numbers.
        """
        stack, res = [], 0
        if root:
            stack.append(root)
        while stack:
            node = stack.pop()
            # If the current node is a leaf node, add its value to the result
            if not node.left and not node.right:
                res += node.val
            # Push the right and left children onto the stack, updating their values to include the path from the root
            if node.right:
                node.right.val += node.val*10
                stack.append(node.right)
            if node.left:
                node.left.val += node.val*10
                stack.append(node.left)
        return res


""" 
Time and Space Complexity Analysis:

    DFS Recursive (sumNumbers1): The time complexity is O(N), where N is the number of nodes in the tree, because each node is visited once. The space complexity is O(H), where H is 
    the height of the tree, due to the recursive call stack.

    BFS with Queue (sumNumbers2): The time complexity is O(N), as each node is visited once. The space complexity is O(N), as in the worst case, all nodes might be in the queue at 
    the same time.

    DFS with Stack (sumNumbers): The time complexity is O(N), as each node is visited once. The space complexity is O(N), as in the worst case, all nodes might be in the stack at the 
    same time.

In summary, all three methods have a linear time complexity in terms of the number of nodes in the tree, but they differ in their space complexity, with the BFS and DFS with stack methods potentially using more space in the worst case.
 """