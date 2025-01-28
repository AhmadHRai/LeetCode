class Solution {
    private:
        // Function to perform BFS and count fishes in the connected component
        int countFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                        int row, int col) {
            int numRows = grid.size(), numCols = grid[0].size(), fishCount = 0;
            queue<pair<int, int>> q;
            q.push({row, col});
            visited[row][col] = true;
    
            // Directions for exploring up, down, left, right
            vector<int> rowDirections = {0, 0, 1, -1};
            vector<int> colDirections = {1, -1, 0, 0};
    
            // BFS traversal
            while (!q.empty()) {
                row = q.front().first;
                col = q.front().second;
                q.pop();
                fishCount += grid[row][col];
    
                // Exploring all four directions
                for (int i = 0; i < 4; i++) {
                    int newRow = row + rowDirections[i];
                    int newCol = col + colDirections[i];
                    if (0 <= newRow && newRow < numRows && 0 <= newCol &&
                        newCol < numCols && grid[newRow][newCol] &&
                        !visited[newRow][newCol]) {
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            return fishCount;
        }
    
    public:
        // Function to find the maximum number of fishes
        int findMaxFish(vector<vector<int>>& grid) {
            int numRows = grid.size(), numCols = grid[0].size(), result = 0;
            vector<vector<bool>> visited(numRows, vector<bool>(numCols));
    
            // Iterating through the entire grid
            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < numCols; j++) {
                    if (grid[i][j] && !visited[i][j]) {
                        result = max(result, countFishes(grid, visited, i, j));
                    }
                }
            }
            return result;
        }
    };

/* 
Algorithm

Main Function: findMaxFish(vector<vector<int>>& grid)

    Initialize Variables:
        numRows and numCols to represent the number of rows and columns in grid.
        result to store the maximum fish count found in any connected component. Initialized to 0.
        visited as a 2D matrix of size numRows x numCols to track visited cells, initialized to false.

    Iterate through the Grid:
        For each cell (i, j) in the grid:
            If the cell contains water (grid[i][j] > 0) and has not been visited, call countFishes(grid, visited, i, j) to calculate the total fish in the connected component starting from (i, j).
            Update result to the maximum of result and the fish count returned by countFishes.

    Return Result:
        After iterating through all cells, return the result.

Helper Function: countFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col)

    Initialize Variables:
        numRows and numCols to represent the dimensions of the grid.
        fishCount to accumulate the number of fish in the connected component, initialized to 0.
        q as a queue for BFS traversal starting from the initial cell (row, col).

    BFS Traversal:
        Push the initial cell (row, col) onto the queue and mark it as visited.
        While the queue is not empty:
            Dequeue the front element to get current coordinates (row, col).
            Add the fish count from the current cell to fishCount.
            Explore all four directions (up, down, left, right) for connected water cells:
                If the neighboring cell is within bounds, contains water, and hasn't been visited, add it to the queue and mark it as visited.

    Return Fish Count:
        After exploring all possible connected cells, return fishCount.

Complexity Analysis

Let m be the number of rows and n be the number of columns in the grid.

    Time Complexity: O(m⋅n)

    In the worst case, where the grid is completely filled with water cells, the algorithm iterates through all m \cdot n cells. For each cell, it performs a Breadth-first search (BFS) to calculate the total fish in the connected region. Therefore, the overall time complexity is O(m⋅n).

    Space Complexity: O(m⋅n)

    The algorithm uses a visited matrix of size m \cdot n to track visited cells. Hence, the overall space complexity is O(m⋅n).

*/