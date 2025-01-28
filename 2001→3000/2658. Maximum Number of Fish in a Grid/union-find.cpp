class Solution {
    private:
        // Helper function to find the root of a component
        int findParent(vector<int>& parent, int cellIndex) {
            if (parent[cellIndex] == cellIndex) {
                return cellIndex;
            }
            return parent[cellIndex] =
                       findParent(parent, parent[cellIndex]);  // Path compression
        }
    
        // Helper function to union two components
        void unionComponents(vector<int>& parent, vector<int>& componentSize,
                             vector<int>& totalFish, int cellIndex1,
                             int cellIndex2) {
            int root1 = findParent(parent, cellIndex1);
            int root2 = findParent(parent, cellIndex2);
    
            if (root1 != root2) {
                // Union by size to optimize tree height
                if (componentSize[root1] < componentSize[root2]) {
                    swap(root1, root2);
                }
                parent[root2] = root1;
                componentSize[root1] += componentSize[root2];
                totalFish[root1] += totalFish[root2];
            }
        }
    
    public:
        int findMaxFish(vector<vector<int>>& grid) {
            int rowCount = grid.size(), columnCount = grid[0].size();
            int totalCells = rowCount * columnCount;
    
            // Initialize Union-Find structures
            vector<int> parent(totalCells);
            vector<int> componentSize(totalCells, 1);
            vector<int> totalFish(totalCells);
    
            // Set initial parent and fish count for each cell
            iota(parent.begin(), parent.end(), 0);
            for (int row = 0; row < rowCount; row++) {
                for (int column = 0; column < columnCount; column++) {
                    int cellIndex = row * columnCount + column;
                    totalFish[cellIndex] = grid[row][column];
                }
            }
    
            // Direction vectors for neighbors (right, left, down, up)
            vector<int> deltaRow{0, 0, 1, -1}, deltaColumn{1, -1, 0, 0};
    
            // Merge connected components
            for (int row = 0; row < rowCount; row++) {
                for (int column = 0; column < columnCount; column++) {
                    if (grid[row][column] >
                        0) {  // Process only water cells with fish
                        int cellIndex = row * columnCount + column;
                        for (int direction = 0; direction < 4; direction++) {
                            int neighborRow = row + deltaRow[direction];
                            int neighborColumn = column + deltaColumn[direction];
                            if (neighborRow >= 0 && neighborRow < rowCount &&
                                neighborColumn >= 0 &&
                                neighborColumn < columnCount &&
                                grid[neighborRow][neighborColumn] > 0) {
                                int neighborIndex =
                                    neighborRow * columnCount + neighborColumn;
                                unionComponents(parent, componentSize, totalFish,
                                                cellIndex, neighborIndex);
                            }
                        }
                    }
                }
            }
    
            // Find the maximum fish in any component
            int maxFish = 0;
            for (int cellIndex = 0; cellIndex < totalCells; cellIndex++) {
                if (findParent(parent, cellIndex) ==
                    cellIndex) {  // Check if cellIndex is a root
                    maxFish = max(maxFish, totalFish[cellIndex]);
                }
            }
            return maxFish;
        }
    };

/* 
Algorithm

    Main Function: findMaxFish(vector<vector<int>>& grid)

        Initialize Variables:
            Determine the number of rows (rows) and columns (cols) in the grid.
            Compute the total number of cells (totalCells) which is rows * cols.

        Union-Find Initialization:
            Create arrays parent, componentSize, and totalFish:
                parent keeps track of the root for each cell.
                componentSize tracks the size of the component (number of cells) each root represents.
                totalFish tracks the total fish count in the connected component represented by each root.
            Use iota(parent.begin(), parent.end(), 0) to initialize parent such that each cell is its own parent initially.

        Setting Initial Fish Count:
            Traverse the grid and populate the totalFish array with the fish count of each cell.

        Union Operation:
            Use direction vectors dRow and dCol to explore neighboring cells (right, left, down, up).
            For each water cell (grid[row][col] > 0), union its connected neighbors using the unionComponents function.

        After processing all cells and merging components, iterate through the totalFish array to find the maximum fish count among all components that have a unique root.

        Return the maximum fish count found.

    Helper Function: unionComponents(vector<int>& parent, vector<int>& componentSize, vector<int>& totalFish, int x, int y)

        Find the root of x: Use findParent to get the root of component containing x.

        Find the root of y: Use findParent to get the root of component containing y.

        Union by size: If the roots are different, attach the smaller tree under the root of the larger tree, ensuring optimization.

        Update Component Size and Fish Count: After merging, update the size of the new component and the total fish count accordingly.

    Helper Function: findParent(vector<int>& parent, int x)

        If parent[x] equals x, then x is its own root. Otherwise, recursively find the parent of parent[x].

Complexity Analysis

Let m be the number of rows and n be the number of columns in the grid.

    Time Complexity: O((n⋅m)⋅α(n⋅m))

        The outer loop iterates over all cells in the grid, which takes O(n⋅m) time.

        For each cell, the algorithm checks its four neighbors (right, left, down, up), which is a constant O(4) operation.

        The findParent and unionComponents operations are performed using the Union-Find data structure with path compression and union by size. These operations have an amortized time complexity of O(α(n⋅m)), where α is the inverse Ackermann function, which is very small and can be considered almost constant.

        Therefore, the overall time complexity is O((n⋅m)⋅α(n⋅m)).

    Space Complexity: O(n⋅m)

        The algorithm uses three auxiliary arrays: parent, componentSize, and totalFish, each of size n⋅m.

        The space required for these arrays is O(n⋅m).

        Additionally, the recursion stack for the findParent function is bounded by the height of the Union-Find tree, which is O(α(n⋅m)) due to path compression. However, this is negligible compared to the space used by the arrays.

        Therefore, the overall space complexity is O(n⋅m).

*/