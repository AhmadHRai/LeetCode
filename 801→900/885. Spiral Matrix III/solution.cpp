class Solution {
public:
    // generate a list of coordinates in a spiral order starting from (r, c) // (int rows, int cols, int rStart, int cStart)
    vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
        // Initialize the result with the starting position (r, c)
        vector<vector<int>> res = {{r, c}};
        
        // Initialize direction vectors; dx, dy will control the movement direction
        int dx = 0, dy = 1, tmp;
        
        // Continue looping until we have visited all cells in the matrix
        for (int n = 0; res.size() < R * C; n++) {
            // Loop through the current layer
            for (int i = 0; i < n / 2 + 1; i++) {
                // Move to the next cell in the current direction
                r += dx;
                c += dy;
                
                // Check if the new cell is within the bounds of the matrix
                if (0 <= r && r < R && 0 <= c && c < C)
                    // Add the valid cell to the result
                    res.push_back({r, c});
            }
            
            // Update direction vectors to turn clockwise
            tmp = dx;     // Store the current dx
            dx = dy;      // Set new dx to current dy
            dy = -tmp;    // Set new dy to the negative of old dx
        }
        
        // Return the list of coordinates
        return res;
    }
};

/*
Approach:
1. Start with the initial position (r, c) and add it to the result list.
2. Use direction vectors (dx, dy) to control the movement in the spiral order. Initialize to move right.
3. Iterate in layers, expanding the spiral:
   - For each layer, move in the current direction and check if the position is within the bounds of the matrix.
   - Update the direction vectors to turn clockwise after completing each layer.
4. Continue the process until all cells in the matrix (R * C) have been visited.

Complexity Analysis:
1. Time Complexity: O(R * C) - Each cell in the matrix is visited exactly once, resulting in a linear time complexity with respect to the number of cells.
2. Space Complexity: O(R * C) - The space used is proportional to the number of cells in the matrix as we store each cell's coordinates in the result vector.
*/
