class Solution {
    private:
        int exploreIsland(vector<vector<int>>& grid, int islandId, int currentRow,
                          int currentColumn) {
            if (currentRow < 0 || currentRow >= grid.size() || currentColumn < 0 ||
                currentColumn >= grid[0].size() ||
                grid[currentRow][currentColumn] != 1)
                return 0;
    
            grid[currentRow][currentColumn] = islandId;
            return 1 +
                   exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
                   exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
                   exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
                   exploreIsland(grid, islandId, currentRow, currentColumn - 1);
        }
    
    public:
        int largestIsland(vector<vector<int>>& grid) {
            unordered_map<int, int> islandSizes;
            int islandId = 2;
    
            // Step 1: Mark all islands and calculate their sizes
            for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
                for (int currentColumn = 0; currentColumn < grid[0].size();
                     ++currentColumn) {
                    if (grid[currentRow][currentColumn] == 1) {
                        islandSizes[islandId] = exploreIsland(
                            grid, islandId, currentRow, currentColumn);
                        ++islandId;
                    }
                }
            }
    
            // If there are no islands, return 1
            if (islandSizes.empty()) {
                return 1;
            }
            // If the entire grid is one island, return its size or size + 1
            if (islandSizes.size() == 1) {
                --islandId;
                return (islandSizes[islandId] == grid.size() * grid[0].size())
                           ? islandSizes[islandId]
                           : islandSizes[islandId] + 1;
            }
    
            int maxIslandSize = 1;
    
            // Step 2: Try converting every 0 to 1 and calculate the resulting
            // island size
            for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
                for (int currentColumn = 0; currentColumn < grid[0].size();
                     ++currentColumn) {
                    if (grid[currentRow][currentColumn] == 0) {
                        int currentIslandSize = 1;
                        unordered_set<int> neighboringIslands;
    
                        // Check down
                        if (currentRow + 1 < grid.size() &&
                            grid[currentRow + 1][currentColumn] > 1) {
                            neighboringIslands.insert(
                                grid[currentRow + 1][currentColumn]);
                        }
    
                        // Check up
                        if (currentRow - 1 >= 0 &&
                            grid[currentRow - 1][currentColumn] > 1) {
                            neighboringIslands.insert(
                                grid[currentRow - 1][currentColumn]);
                        }
    
                        // Check right
                        if (currentColumn + 1 < grid[0].size() &&
                            grid[currentRow][currentColumn + 1] > 1) {
                            neighboringIslands.insert(
                                grid[currentRow][currentColumn + 1]);
                        }
    
                        // Check left
                        if (currentColumn - 1 >= 0 &&
                            grid[currentRow][currentColumn - 1] > 1) {
                            neighboringIslands.insert(
                                grid[currentRow][currentColumn - 1]);
                        }
    
                        // Sum the sizes of all unique neighboring islands
                        for (int id : neighboringIslands) {
                            currentIslandSize += islandSizes[id];
                        }
    
                        maxIslandSize = max(maxIslandSize, currentIslandSize);
                    }
                }
            }
    
            return maxIslandSize;
        }
    };

/* 
Algorithm
exploreIsland helper function:

    Define the exploreIsland function which recursively explores an island with the given id islandId starting from the given cell (currentRow, currentColumn).

    Check if the current cell is out of bounds, is not part of an island or is already visited (i.e., its value is not 1):
        If so, return 0, indicating no land is found at this cell.

    Mark the current cell with the given islandId to indicate it has been visited.

    Recursively explore the four neighboring cells (up, down, left, right) and accumulate the area of the island:
        Call exploreIsland for the cell below (currentRow + 1, currentColumn).
        Call exploreIsland for the cell above (currentRow - 1, currentColumn).
        Call exploreIsland for the cell to the right (currentRow, currentColumn + 1).
        Call exploreIsland for the cell to the left (currentRow, currentColumn - 1).

    Return the total area of the island (i.e., 1 + the sum of all reachable land cells from the current position).

largestIsland main function:

    Initialize islandSizes to store sizes of islands, and islandId starting at 2 (to mark islands).

    Traverse through the grid to mark all islands and calculate their sizes:
        For each cell in the grid, if the cell contains a land (value 1), call exploreIsland() to mark the island and calculate its size.
        For each island, store the size in islandSizes using the islandId as the key and increment islandId for the next island.

    Check if there are no islands (empty grid), in which case return 1 (since flipping one 0 would form a new island).

    If only one island exists in the entire grid, check if the size of that island is equal to the total grid size:
        If true, return the size of the island.
        Otherwise, return the size of the island + 1 (as we can expand the island by flipping one 0).

    Initialize maxIslandSize to 1, which will store the size of the largest island.

    Traverse through the grid again to try converting each 0 to a 1 and calculate the resulting island size:
        For each 0, check its neighboring cells (up, down, left, right) to find which islands are connected to it.
        Use a unordered set to store unique neighboring island IDs.
        Sum the sizes of all unique neighboring islands and add 1 (to account for the flipped 0 turning into a 1).
        Update maxIslandSize with the maximum island size found.

    Return maxIslandSize, the size of the largest island after trying to expand all possible 0s.

Complexity Analysis
    Let n be the number of rows in the grid, m be the number of columns in the grid.

    Time complexity: O(n×m)

        The algorithm consists of two main phases. In the first phase, we iterate over every cell in the grid to identify and mark islands using a Depth-First 
        Search (DFS) approach. During this process, each cell is visited at most once, ensuring that the DFS traversal contributes O(n×m) to the time complexity.

        In the second phase, we iterate over every cell again to explore the possibility of converting each 0 to 1 and calculating the potential island size. For 
        each 0, we check its four neighboring cells, which is a constant-time operation. The use of an unordered set ensures that neighboring islands are counted 
        uniquely, and the total work done in this phase is also O(n×m).

        Thus, the overall time complexity is dominated by the grid traversal and DFS, resulting in O(n×m).

    Space complexity: O(n×m)

        The space complexity is primarily determined by the recursion stack used during the DFS traversal and the storage required for the unordered map that 
        keeps track of island sizes. In the worst case, the recursion depth of the DFS can be O(n×m) if the entire grid forms a single large island. The unordered 
        map stores the sizes of all islands, and in the worst case, the number of islands can be proportional to the number of cells, contributing O(n×m) to the 
        space complexity.

        Furthermore, the unordered set used to store neighboring islands for each 0 cell has a maximum size of 4, as there are only four possible neighboring 
        cells. This does not significantly impact the overall space complexity.

        Therefore, the dominant factors are the recursion stack and the unordered map, resulting in an overall space complexity of O(n×m).

*/