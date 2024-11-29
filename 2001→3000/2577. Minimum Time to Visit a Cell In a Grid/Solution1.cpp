class Solution {
public:
    // Function to find the minimum time to visit the bottom-right cell
    int minimumTime(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(); // Get dimensions of the grid
        
        // Check if it's impossible to move to the right or down from the starting position
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1; // Return -1 if both moves are blocked
        }

        // Directions for moving in the grid: down, up, right, left
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Visited array to keep track of visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Priority queue to process cells based on time (min-heap)
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        pq.push({0, 0, 0}); // Push starting cell with time 0

        while (!pq.empty()) {
            auto current = pq.top(); // Get the cell with the minimum time
            int time = current[0], row = current[1], col = current[2];
            pq.pop(); // Remove the cell from the priority queue
            
            // Check if we've reached the bottom-right cell
            if (row == rows - 1 && col == cols - 1) {
                return time; // Return the time taken to reach this cell
            }

            // Skip if this cell has already been visited
            if (visited[row][col]) {
                continue;
            }
            
            visited[row][col] = true; // Mark this cell as visited
            
            // Explore adjacent cells
            for (const auto& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1]; // Calculate new cell coordinates
                
                // Check bounds and if the cell is already visited
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || visited[newRow][newCol]) {
                    continue; // Skip invalid or visited cells
                }
                
                // Determine if we need to wait before visiting this cell
                bool wait = (grid[newRow][newCol] - time) % 2 == 0;
                
                // Calculate the next time we can visit this cell
                int nextTime = max(grid[newRow][newCol] + wait, time + 1);
                
                pq.push({nextTime, newRow, newCol}); // Push the new state into the priority queue
            }
        }
        
        return -1; // Return -1 if we cannot reach the bottom-right cell
    }
};

/*
Approach:
    This solution employs a **modified Dijkstra's algorithm** approach using a **priority queue** to find the minimum time required to reach the bottom-right cell in a 
    grid. The algorithm processes cells based on their visitable times and explores adjacent cells accordingly.

Complexity:
    Time Complexity: O(m * n * log(m * n)), where m is the number of rows and n is the number of columns. Each cell can be pushed into the priority queue once.
    Space Complexity: O(m * n) for storing the visited status and priority queue.
*/
