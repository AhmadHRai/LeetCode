class Solution {
    public:
        vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
            int dx[4] = {0, 0, 1,
                         -1};  // Horizontal movement: right, left, down, up
            int dy[4] = {1, -1, 0, 0};  // Vertical movement corresponding to dx
    
            int rows = isWater.size();
            int columns = isWater[0].size();
    
            // Initialize the height matrix with -1 (unprocessed cells)
            vector<vector<int>> cellHeights(rows, vector<int>(columns, -1));
    
            queue<pair<int, int>> cellQueue;
    
            // Add all water cells to the queue and set their height to 0
            for (int x = 0; x < rows; x++) {
                for (int y = 0; y < columns; y++) {
                    if (isWater[x][y]) {
                        cellQueue.push({x, y});
                        cellHeights[x][y] = 0;
                    }
                }
            }
    
            // Initial height for land cells adjacent to water
            int heightOfNextLayer = 1;
    
            while (!cellQueue.empty()) {
                int layerSize = cellQueue.size();
    
                // Iterate through all cells in the current layer
                for (int i = 0; i < layerSize; i++) {
                    pair<int, int> currentCell = cellQueue.front();
                    cellQueue.pop();
    
                    // Check all four possible directions for neighboring cells
                    for (int d = 0; d < 4; d++) {
                        pair<int, int> neighborCell = {currentCell.first + dx[d],
                                                       currentCell.second + dy[d]};
    
                        // Check if the neighbor is valid and unprocessed
                        if (isValidCell(neighborCell, rows, columns) &&
                            cellHeights[neighborCell.first][neighborCell.second] ==
                                -1) {
                            cellHeights[neighborCell.first][neighborCell.second] =
                                heightOfNextLayer;
                            cellQueue.push(neighborCell);
                        }
                    }
                }
                heightOfNextLayer++;  // Increment height for the next layer
            }
    
            return cellHeights;
        }
    
    private:
        // Function to check if a cell is within the grid boundaries
        bool isValidCell(pair<int, int> cell, int rows, int columns) {
            return cell.first >= 0 && cell.second >= 0 && cell.first < rows &&
                   cell.second < columns;
        }
    };

/* 
Algorithm

    Define two arrays of size 4: dx = [0, 0, 1, -1] and dy = [1, -1, 0, 0]. Each pair (dx[d], dy[d]) represents one of the four possible directions to an adjacent cell.
    Initialize a 2D matrix, named cellHeights, of the same dimension as isWater. Set all of its cells to an invalid value, i.e. -1.
    Initialize an empty queue of pairs, cellQueue.
    Iterate over the isWater matrix:
        Push every water cell into the cellQueue.
        Set the height of each water cell to be 0.
    Initialize heightOfNextLayer to 1 - that is the height of the neighbors of the cells currently in queue.
    While the cellQueue is not empty:
        Set layerSize to the size of the queue.
        For each cell in the current layer, i.e. for i from 0 to layerSize - 1:
            Pop the top cell currentCell out of the queue.
            For each direction, i.e. for d from 0 to 3:
                Find the neighbor of the current cell to that direction, neighborCell = (currentCell.x + dx[d], currentCell.y + dy[d]).
                If neighbor is a valid cell (i.e. it is not out of the bounds of the matrix) and it is not already visited (i.e. cellHeights[neighbor.x][neighbor.y] == -1):
                    Set cellHeights[neighbor.x][neighbor.y] to heightOfNextLayer.
                    Push neighbor into the cellQueue.
        Increment heightOfNextLayer by 1.
    Return cellHeights.

Editorial
Solutions
Solutions
Submissions
Submissions
Code
Code
Accepted
Testcase
Test Result
Test Result
Map of Highest Peak
Map of Highest Peak
LeetCode
32587
Jan 10, 2025
Editorial
Solution
Overview

We are given a 2D matrix isWater of dimensions m x n, which represents a map consisting of land and water cells. Specifically:

    If isWater[i][j] = 0, the cell (i, j) represents land.
    If isWater[i][j] = 1, the cell (i, j) represents water.

The goal is to assign a height to each cell such that the highest peak on the map (i.e., the greatest height of any cell) is as high as possible. This assignment must follow these rules:

    The height of each cell must be non-negative.
    The height of all water cells is fixed at 0. These cells have fixed heights and cannot be changed.
    The height difference between two adjacent cells (cells that share a side) must not be greater than one. For example, if the height of cell (2, 3) is 4, then the heights of its adjacent cells—(1, 3), (3, 3), (2, 4), and (2, 2)—must be either 3, 4 or 5.

Approach 1: Breadth-First Search
Intuition

Let’s first break the problem down into a simpler, one-dimensional version.

Imagine a row of cells with only one water cell. Intuitively, as we move away from the water cell, the heights of the land cells should gradually increase. The height of each land cell can naturally be determined by its distance from the water cell.

One-dimensional version of the problem with a single water cell

Now, let’s add a second water cell to the row. The idea stays the same, but now each land cell’s height is determined by its smallest distance to any water cell. This ensures a smooth increase in height as we move away from both water cells.

One-dimensional version of the problem with two water cells

When we extend this logic to two dimensions, the concept is identical. For every cell in the grid, we calculate its smallest distance to any water cell and assign that value as its height.

    Heights increase smoothly from water cells, ensuring the highest peak is at the farthest distance from all water cells.
    This can be visualized as a "ripple effect" where water cells propagate their distances outward, assigning heights to nearby land cells.

Two-dimensional version

This approach works intuitively for two reasons:

    It follows the rule that the height difference between two adjacent cells is at most one. This is because the minimum distance to water for any two neighboring cells cannot differ by more than one.
    It’s optimal because it ensures that the height of the cells increases consistently as we move farther from water cells, maximizing the highest peak on the map.

To find the shortest distance from any cell to a water cell, we use Breadth-First Search (BFS) starting from all water cells. When a land cell is reached for the first time, its shortest distance to a water cell is set.

    For a more comprehensive understanding of breadth-first search, check out the BFS Explore Card 🔗. This resource provides an in-depth look at BFS, explaining its key concepts and applications with a variety of problems to solidify understanding of the pattern.

Algorithm

    Define two arrays of size 4: dx = [0, 0, 1, -1] and dy = [1, -1, 0, 0]. Each pair (dx[d], dy[d]) represents one of the four possible directions to an adjacent cell.
    Initialize a 2D matrix, named cellHeights, of the same dimension as isWater. Set all of its cells to an invalid value, i.e. -1.
    Initialize an empty queue of pairs, cellQueue.
    Iterate over the isWater matrix:
        Push every water cell into the cellQueue.
        Set the height of each water cell to be 0.
    Initialize heightOfNextLayer to 1 - that is the height of the neighbors of the cells currently in queue.
    While the cellQueue is not empty:
        Set layerSize to the size of the queue.
        For each cell in the current layer, i.e. for i from 0 to layerSize - 1:
            Pop the top cell currentCell out of the queue.
            For each direction, i.e. for d from 0 to 3:
                Find the neighbor of the current cell to that direction, neighborCell = (currentCell.x + dx[d], currentCell.y + dy[d]).
                If neighbor is a valid cell (i.e. it is not out of the bounds of the matrix) and it is not already visited (i.e. cellHeights[neighbor.x][neighbor.y] == -1):
                    Set cellHeights[neighbor.x][neighbor.y] to heightOfNextLayer.
                    Push neighbor into the cellQueue.
        Increment heightOfNextLayer by 1.
    Return cellHeights.

Implementation
Complexity Analysis

Let m be the number of rows and n the number of columns in the isWater matrix.

    Time Complexity: O(m×n)
    We perform a single multi-source BFS traversal over the cells of the matrix. The time complexity of BFS is O(V+E), where V is the number of vertices (cells in the grid, m×n) and E is the number of edges (connections between neighboring cells).

    In a grid, each cell has at most 4 neighbors, resulting in at most 4⋅m×n edges. Since E is proportional to V in a grid, the total time complexity simplifies to O(m×n).

    Space Complexity: O(m×n)
    We use a 2D matrix cellHeights of size m×n to store the calculated heights. Additionally, the BFS queue can hold up to m×n cells in the worst case. Therefore, the overall space complexity is O(m×n).
*/