class Solution {
private:
    // Directions for movement: right, left, down, up
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    // Function to find the minimum number of obstacles to reach the bottom-right corner of the grid
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); // Get the dimensions of the grid

        // Distance matrix to store the minimum obstacles removed to reach each cell
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        minObstacles[0][0] = 0; // Starting cell has zero obstacles removed

        // Deque to manage cells for BFS
        deque<array<int, 3>> deque;
        deque.push_back({0, 0, 0});  // {obstacles, row, col}

        // While there are cells to process in the deque
        while (!deque.empty()) {
            auto current = deque.front(); // Get the front cell
            deque.pop_front(); // Remove it from the deque
            int obstacles = current[0], row = current[1], col = current[2];

            // Explore all four possible directions from the current cell
            for (auto& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                // Check if the new position is valid and unvisited
                if (isValid(grid, newRow, newCol) &&
                    minObstacles[newRow][newCol] == INT_MAX) {
                    if (grid[newRow][newCol] == 1) {
                        // If it's an obstacle, add 1 to obstacles and push to the back of the deque
                        minObstacles[newRow][newCol] = obstacles + 1;
                        deque.push_back({obstacles + 1, newRow, newCol});
                    } else {
                        // If it's an empty cell, keep the obstacle count and push to the front of the deque
                        minObstacles[newRow][newCol] = obstacles;
                        deque.push_front({obstacles, newRow, newCol});
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1]; // Return minimum obstacles to reach bottom-right corner
    }

private:
    // Helper method to check if the cell is within grid bounds
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};

/*
0-1 Breadth-First Search (BFS)

Intuition:
The problem can be framed as a shortest-path problem where moving through cells without obstacles has no cost. To prioritize exploring neighboring empty cells first and only moving to cells with obstacles when no free cells are left, we can use a double-ended queue (deque).

We perform a BFS using a deque to manage our exploration. When exploring neighboring cells:
- Empty cells are added to the front of the deque for immediate exploration.
- Cells with obstacles are added to the back of the deque, delaying their exploration.

We maintain a result grid `minObstacles`, initialized to infinity (indicating unvisited), to track the minimum obstacles encountered at each cell. Starting from the top-left cell, we explore its neighbors. All empty neighbors go to the front of the deque while others go to the back with their obstacle count increased by one. We simultaneously update `minObstacles` for each neighboring position.

Once all cells are explored, the value at `minObstacles[m-1][n-1]` will give us the minimum obstacles encountered on the shortest path.

Algorithm:
1. Initialize a 2-D array `directions` containing four pairs of coordinates representing possible movements: right (0,1), left (0,-1), down (1,0), and up (-1,0).

Main method `minimumObstacles`:
- Store dimensions of the grid in variables `m` (rows) and `n` (columns).
- Initialize a 2-D array `minObstacles` of size m×n to track minimum obstacles needed to reach each cell.
- Initialize all cells in `minObstacles` with infinity to represent unvisited cells.
- Set starting cell `minObstacles[0][0]` to 0.
- Create a double-ended queue `deque` for processing cells and add starting position.
- Loop while `deque` is not empty:
    - Extract first cell from `deque`.
    - For each possible direction:
        - Calculate new position coordinates.
        - If valid and unvisited:
            - If it contains an obstacle (value 1):
                - Update `minObstacles` with current count plus one.
                - Add new position to back of `deque`.
            - If it is empty (value 0):
                - Update `minObstacles` with current count.
                - Add new position to front of `deque`.
- Return value in `minObstacles[m-1][n-1]`.

Helper method `isValid(row, col)`:
- Return true if row and col lie within grid boundaries; false otherwise.

Complexity Analysis:
Let m be the number of rows and n be the number of columns in the grid.

Time complexity: O(m⋅n)
Each of the m⋅n cells in the grid is visited exactly once because we only process unvisited cells. The deque operations are all O(1). Thus, total time complexity is O(m⋅n).

Space complexity: O(m⋅n)
The space complexity is dominated by two main components: 
- The `minObstacles` array which has size O(m⋅n).
- The `deque`, which can also grow up to O(m⋅n) in size. Other variables take constant space.

Therefore, overall space complexity remains O(m⋅n).

Runtime:    128 ms
Memory:     130.8 MB
*/
