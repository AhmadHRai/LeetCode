from typing import List
from collections import defaultdict

class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        direct_child = defaultdict(list)  # Dictionary to store direct children of each node
        ans = [[] for _ in range(n)]  # Initialize a list of lists to store ancestors for each node
        
        # Populate direct_child with direct children from edges
        for x, y in edges:
            direct_child[x].append(y)

        # Depth-first search function to find ancestors of each node
        def dfs(x, curr):
            for ch in direct_child[curr]:  # Traverse through direct children of current node
                if ans[ch] and ans[ch][-1] == x:
                    continue  # Skip if current node is already recorded as ancestor of child
                ans[ch].append(x)  # Append current node as ancestor of child
                dfs(x, ch)  # Recursively find ancestors of child node

        # Perform DFS for each node to find all ancestors
        for i in range(n):
            dfs(i, i)
        
        return ans  # Return list of ancestors for each node

"""
Approach:
- Use a defaultdict to store direct children for each node based on the given edges.
- Initialize a list of lists 'ans' where ans[i] will store the ancestors of node i.
- Populate direct_child by iterating through edges and storing each y as a child of x.
- Implement a depth-first search (DFS) function 'dfs' that recursively finds ancestors of a node x.
- In dfs, for each child ch of curr (current node), if curr is not already recorded as an ancestor of ch, record it.
- Perform DFS starting from each node to find all ancestors and store them in 'ans'.
- Return 'ans' which contains the list of ancestors for each node.

Complexity Analysis:
- Time Complexity: O(n + e), where n is the number of nodes and e is the number of edges.
  - Building the direct_child dictionary takes O(e) time.
  - Performing DFS for each node takes O(n + e) time in total.
- Space Complexity: O(n + e), where n is the space used by the 'ans' list and e is the space used by direct_child.
  - The 'ans' list and direct_child dictionary both use space proportional to the number of nodes and edges.
  - Additional space is used for the recursive stack during DFS, which can go up to O(n) in the worst case.
"""

