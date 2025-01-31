class DisjointSet {
    public:
        vector<int> parent;
        vector<int> islandSize;
    
        // Constructor to initialize DSU with `n` elements
        DisjointSet(int n) {
            parent.resize(n);
            islandSize.resize(n);
            for (int node = 0; node < n; node++) {
                // Each node is its own parent initially with size 1
                parent[node] = node;
                islandSize[node] = 1;
            }
        }
    
        // Function to find the root of a node with path compression
        int findRoot(int node) {
            if (parent[node] == node) return node;
            return parent[node] = findRoot(parent[node]);
        }
    
        // Function to union two sets based on size
        void unionNodes(int nodeA, int nodeB) {
            int rootA = findRoot(nodeA);
            int rootB = findRoot(nodeB);
    
            // Already in the same set
            if (rootA == rootB) return;
    
            // Union by size: Attach the smaller island to the larger one
            if (islandSize[rootA] < islandSize[rootB]) {
                // Attach rootA to rootB
                parent[rootA] = rootB;
                // Update size of rootB's island
                islandSize[rootB] += islandSize[rootA];
            } else {
                // Attach rootB to rootA
                parent[rootB] = rootA;
                // Update size of rootA's island
                islandSize[rootA] += islandSize[rootB];
            }
        }
    };
    
    class Solution {
    public:
        int largestIsland(vector<vector<int>>& grid) {
            int rows = grid.size();
            int columns = grid[0].size();
    
            // Initialize DSU for the entire grid
            DisjointSet ds(rows * columns);
    
            // Direction vectors for traversing up, down, left, and right
            vector<int> rowDirections = {1, -1, 0, 0};
            vector<int> columnDirections = {0, 0, 1, -1};
    
            // Step 1: Union adjacent `1`s in the grid
            for (int currentRow = 0; currentRow < rows; currentRow++) {
                for (int currentColumn = 0; currentColumn < columns;
                     currentColumn++) {
                    if (grid[currentRow][currentColumn] == 1) {
                        // Flatten 2D index to 1D
                        int currentNode = (columns * currentRow) + currentColumn;
    
                        for (int direction = 0; direction < 4; direction++) {
                            int neighborRow = currentRow + rowDirections[direction];
                            int neighborColumn =
                                currentColumn + columnDirections[direction];
    
                            // Check bounds and ensure the neighbor is also `1`
                            if (neighborRow >= 0 && neighborRow < rows &&
                                neighborColumn >= 0 && neighborColumn < columns &&
                                grid[neighborRow][neighborColumn] == 1) {
                                int neighborNode =
                                    columns * neighborRow + neighborColumn;
                                ds.unionNodes(currentNode, neighborNode);
                            }
                        }
                    }
                }
            }
    
            // Step 2: Calculate the maximum possible island size
            int maxIslandSize = 0;
            // Flag to check if there are any zeros in the grid
            bool hasZero = false;
            // To store unique roots for a `0`'s neighbors
            unordered_set<int> uniqueRoots;
    
            for (int currentRow = 0; currentRow < rows; currentRow++) {
                for (int currentColumn = 0; currentColumn < columns;
                     currentColumn++) {
                    if (grid[currentRow][currentColumn] == 0) {
                        hasZero = true;
                        // Start with the flipped `0`
                        int currentIslandSize = 1;
    
                        for (int direction = 0; direction < 4; direction++) {
                            int neighborRow = currentRow + rowDirections[direction];
                            int neighborColumn =
                                currentColumn + columnDirections[direction];
    
                            // Check bounds and ensure the neighbor is `1`
                            if (neighborRow >= 0 && neighborRow < rows &&
                                neighborColumn >= 0 && neighborColumn < columns &&
                                grid[neighborRow][neighborColumn] == 1) {
                                int neighborNode =
                                    columns * neighborRow + neighborColumn;
                                int root = ds.findRoot(neighborNode);
                                uniqueRoots.insert(root);
                            }
                        }
    
                        // Sum up the sizes of unique neighboring islands
                        for (int root : uniqueRoots) {
                            currentIslandSize += ds.islandSize[root];
                        }
    
                        // Clear the set for the next `0`
                        uniqueRoots.clear();
    
                        // Update the result with the largest island size found
                        maxIslandSize = max(maxIslandSize, currentIslandSize);
                    }
                }
            }
    
            // If there are no zeros, the largest island is the entire grid
            if (!hasZero) return rows * columns;
    
            return maxIslandSize;
        }
    };

/* 
Algorithm
Define the DisjointSet class:

    Initialize parent and islandSize arrays:
        parent stores the parent of each node.
        islandSize stores the size of the connected island for each root.

    Initialize the DisjointSet constructor with n elements:
        For each node from l to n-1:
            Set parent[node] = node, meaning each node is initially its own parent.
            Set islandSize[node] = 1, indicating each island starts with size 1.

    Implement findRoot function with path compression:
        If the current node is its own parent, return the node as the root.
        Otherwise, recursively find the root of the parent and apply path compression by updating the parent of the node.

    Implement unionNodes(nodeA, nodeB) function to union two sets based on size:
        Find the roots of both nodeA and nodeB using the findRoot function.
        If both nodes are already in the same set (i.e., have the same root), do nothing.
        Otherwise, union the sets by size:
            Attach the smaller island to the larger one:
                If the island of nodeA is smaller, set parent[rootA] = rootB and update the size of rootB’s island.
                If the island of nodeB is smaller, set parent[rootB] = rootA and update the size of rootA’s island.

In the given Solution class:

    Initialize rows and columns to store the grid's dimensions.

    Initialize a Disjoint Set Union (DSU) for the entire grid with rows * columns size.

    Define direction arrays (rowDirections, columnDirections) for traversing up, down, left, and right.

Step 1: Union adjacent 1s in the grid:

    Iterate through each cell in the grid:
        If the current cell contains 1, calculate the flattened 1D index for the current cell, as (columns * currentRow) + currentColumn.
        For each of the four possible directions (up, down, left, right), check if the neighbor is within bounds and also contains 1.
        If the neighbor is valid, flatten the 2D index and use the DSU to union the current cell and the neighbor.

Step 2: Calculate the maximum possible island size:

    Initialize maxIslandSize to store the largest island size and hasZero as a flag to check if there are any zeros in the grid.
    Initialize a uniqueRoots set to store the unique roots of neighboring 1s for each 0 in the grid.
    Iterate through the grid to find all zeros (0 cells):
        For each 0, initialize the currentIslandSize to 1 (since we are flipping the 0).
        For each direction (up, down, left, right), check if the neighboring cell contains 1 and if so, add the root of the neighboring island to uniqueRoots.
        Sum the sizes of the unique neighboring islands using their roots.
        Update maxIslandSize with the largest island size found.

Step 3: Return the result:

    If there are no zeros in the grid, return the size of the entire grid (i.e., rows * columns).
    Otherwise, return maxIslandSize, the largest island size after flipping a zero.


Complexity Analysis

Let n be the number of rows in the grid, m be the number of columns in the grid.

    Time complexity: O(n×m)

    The algorithm consists of two main phases. In the first phase, we iterate over every cell in the grid and we use a Disjoint Set Union (DSU) data structure to union adjacent 1s. For each cell, we check its four neighboring cells, which is a constant-time operation. The DSU operations, including findRoot and unionNodes, are nearly constant time due to path compression and union by size optimizations. Thus, the first phase contributes O(n×m) to the time complexity.

    In the second phase, we iterate over every cell again to explore the possibility of converting each 0 to 1 and calculating the potential island size. For each 0, we check its four neighboring cells and use the DSU to find the roots of neighboring islands. The unordered set ensures that neighboring islands are counted uniquely, and the total work done in this phase is also O(n×m).

    Therefore, the overall time complexity is dominated by the grid traversal and DSU operations, resulting in O(n×m).

    Space complexity: O(n×m)

    The space complexity is primarily determined by the DSU data structure, which stores the parent and size of each cell. Both the parent and islandSize arrays require O(n×m) space. Additionally, the unordered set used to store unique roots for neighboring islands has a maximum size of 4, as there are only four possible neighboring cells. This does not significantly impact the overall space complexity.

    Therefore, the dominant factor is the DSU data structure, resulting in an overall space complexity of O(n×m).
*/