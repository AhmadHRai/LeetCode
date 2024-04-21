class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        // Iterate through each cell in the grid
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                // Check if the current cell is part of the island (represented by 1)
                if(grid[i][j] == 1) {
                    count++; // Increment count for each island cell
                    // Check if the cell above is also part of the island
                    if(i != 0 && grid[i-1][j] == 1) repeat++;
                    // Check if the cell to the left is also part of the island
                    if(j != 0 && grid[i][j-1] == 1) repeat++;
                }
            }
        }
        // Calculate the perimeter of the island
        // Each cell contributes 4 edges to the perimeter, but shared edges are counted twice, so subtract the number of shared edges
        return 4*count - repeat*2;
    }
};

/* 
Approach:
    The goal of this code is to calculate the perimeter of the island represented by a 2D grid. An island is represented by 1s in the grid, and the perimeter is the 
    total number of edges that are not shared by two 1s.

Algorithm:
    1. Initialize two counters: `count` to keep track of the total number of cells with 1s (representing the island) and `repeat` to count the number of edges that are 
    shared by two 1s.
    
    2. Iterate through each cell in the grid. If a cell contains a 1, increment `count`.
    
    3. For each cell containing a 1, check its neighboring cells (top, left, right, and bottom). If a neighboring cell also contains a 1, increment `repeat` by 2 (since 
    each shared edge contributes to the perimeter twice).
    
    4. After iterating through all cells, calculate the perimeter as `4*count - repeat*2`. This formula accounts for the fact that each cell contributes 4 edges to the 
    perimeter, but shared edges are counted twice, so they need to be subtracted.

Complexity:
    - Time complexity: O(n*m), where n and m are the dimensions of the grid. This is because we need to visit each cell in the grid once.
    - Space complexity: O(1), as we only use a constant amount of space to store the counters and do not use any additional data structures.
*/
