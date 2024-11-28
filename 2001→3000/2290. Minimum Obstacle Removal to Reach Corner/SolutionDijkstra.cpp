class Solution {
private:
    // Directions for movement: right, left, down, up
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    // Function to find the minimum number of obstacles to reach the bottom-right corner of the grid
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); // Get the dimensions of the grid

        // Initialize a 2D array to track the minimum obstacles needed to reach each cell
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        // Start from the top-left corner, accounting for its obstacle value
        minObstacles[0][0] = grid[0][0];

        // Priority queue to process cells based on the number of obstacles removed so far
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        // Add the starting cell to the priority queue
        pq.push({minObstacles[0][0], 0, 0});

        // While there are cells to process in the priority queue
        while (!pq.empty()) {
            // Process the cell with the fewest obstacles removed so far
            vector<int> current = pq.top(); // Get the cell with minimum obstacles
            pq.pop(); // Remove it from the queue
            int obstacles = current[0], row = current[1], col = current[2];

            // If we've reached the bottom-right corner, return the result
            if (row == m - 1 && col == n - 1) {
                return obstacles;
            }

            // Explore all four possible directions from the current cell
            for (vector<int>& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                // Check if the new position is valid within the grid bounds
                if (isValid(grid, newRow, newCol)) {
                    // Calculate the total obstacles removed if moving to the new cell
                    int newObstacles = obstacles + grid[newRow][newCol];

                    // Update if we've found a path with fewer obstacles to the new cell
                    if (newObstacles < minObstacles[newRow][newCol]) {
                        minObstacles[newRow][newCol] = newObstacles; // Update minimum obstacles for this cell
                        pq.push({newObstacles, newRow, newCol}); // Add new position to priority queue
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1]; // Return minimum obstacles to reach bottom-right corner
    }

    // Helper method to check if the cell is within grid bounds
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};

/*
Approach:
The solution employs Dijkstra's algorithm to find the minimum number of obstacles that must be removed to create a path from the top-left corner to the bottom-right corner of a grid. The algorithm treats each cell in the grid as a node in a graph where edges represent valid moves (up, down, left, right) between cells.

1. **Initialization**:
   - A `directions` array is defined to represent possible movements in four directions.
   - The dimensions of the grid are stored in variables `m` and `n`.
   - A `minObstacles` 2D array is initialized with `INT_MAX` values to track the minimum number of obstacles removed to reach each cell. The starting cell's value is set based on its obstacle status.

2. **Priority Queue**:
   - A priority queue is used to explore cells based on their obstacle count in ascending order. The starting position is added first.

3. **Processing Cells**:
   - While there are cells in the priority queue:
     - The cell with the least number of obstacles is processed.
     - If this cell is the target (bottom-right corner), its obstacle count is returned.
     - For each possible move direction, valid neighboring cells are checked.
     - If moving to a neighbor results in fewer obstacles than previously recorded, update its count and add it back into the priority queue for further exploration.

4. **Return Result**:
   - If all cells are processed without reaching the target (which should not happen), return `minObstacles[m-1][n-1]`.

Complexity Analysis:
- **Time Complexity**: O(m⋅n log(m⋅n))
   The priority queue can contain up to O(m⋅n) elements (all cells in the grid). Each operation on this queue takes O(log(m⋅n)) time due to heap properties. Thus, overall time complexity is O(m⋅n log(m⋅n)).

- **Space Complexity**: O(m⋅n)
   The space complexity is dominated by two main components: 
   1. The `minObstacles` array which has a size of O(m⋅n).
   2. The priority queue also has a maximum size of O(m⋅n). 
   Other variables take constant space.

Therefore, overall space complexity is O(m⋅n).

Runtime: 1035 ms
Memory: 234.1 MB
*/
