class Solution {
public:
    // Direction vectors: right, left, down, up (matching grid values 1, 2, 3,
    // 4)
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        // Min-heap ordered by cost. Each element is {cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));
        minCost[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0], row = curr[1], col = curr[2];

            // Skip if we've found a better path to this cell
            if (minCost[row][col] != cost) continue;

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                // Check if new position is valid
                if (newRow >= 0 && newRow < numRows && newCol >= 0 &&
                    newCol < numCols) {
                    // Add cost=1 if we need to change direction
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

                    // Update if we found a better path
                    if (minCost[newRow][newCol] > newCost) {
                        minCost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }
};

/*  
Complexity Analysis

Let n be the number of rows and m be the number of columns in the grid.

    Time Complexity: O(n⋅m⋅log(n⋅m))

    The algorithm uses Dijkstra's algorithm with a priority queue. In the worst case, we might need to visit each cell multiple times until we find the optimal path, but no more than 4 times per cell (once for each direction). For each cell, we perform a priority queue operation which takes O(log(n⋅m)) time, where n⋅m is the maximum size of the queue. Therefore, the total time complexity is O(n⋅m⋅log(n⋅m)).

    Space Complexity: O(n⋅m)

    The algorithm uses a priority queue that in the worst case might contain all cells of the grid, taking O(n⋅m) space. We also maintain the minCost array of size n×m. Therefore, the total space complexity is O(n⋅m).

*/